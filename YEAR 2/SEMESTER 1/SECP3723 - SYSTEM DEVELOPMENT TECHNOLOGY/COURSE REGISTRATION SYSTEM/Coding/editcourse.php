<?php
include('crssession.php');
if (!session_id()) {
    session_start();
}
include 'db_connect.php'; // Keep database connection at the top

// ** Handle the form submission to update course data **
if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['c_code']) && !isset($_POST['delete_course'])) {
    $c_code = mysqli_real_escape_string($con, $_POST['c_code']);
    $c_name = mysqli_real_escape_string($con, $_POST['c_name']);
    $c_credit = (int)$_POST['c_credit'];
    $c_lec = mysqli_real_escape_string($con, $_POST['c_lec']);
    $c_max = (int)$_POST['c_max'];

    $update_query = "
        UPDATE tb_course
        SET c_name = '$c_name', c_credit = $c_credit, c_lec = '$c_lec', c_max = $c_max
        WHERE c_code = '$c_code'
    ";

    if (mysqli_query($con, $update_query)) {
        header('Location: editcourse.php?success=true');
        exit();
    } else {
        echo '<p class="mt-3 text-danger">Error updating course: ' . mysqli_error($con) . '</p>';
    }
}

// ** Handle course deletion **
if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['delete_course'])) {
    $c_code = mysqli_real_escape_string($con, $_POST['c_code']);
    $delete_query = "DELETE FROM tb_course WHERE c_code = '$c_code'";
    
    if (mysqli_query($con, $delete_query)) {
        header('Location: editcourse.php?deleted=true');
        exit();
    } else {
        echo '<p class="mt-3 text-danger">Error deleting course: ' . mysqli_error($con) . '</p>';
    }
}

// Fetch courses based on semester selection (AJAX Request)
if (isset($_GET['fetch_courses']) && isset($_GET['c_sem'])) {
    $selected_semester = mysqli_real_escape_string($con, $_GET['c_sem']);
    $courses_query = "SELECT * FROM tb_course WHERE c_sem = '$selected_semester'";
    $courses_result = mysqli_query($con, $courses_query);

    if (mysqli_num_rows($courses_result) > 0) {
        echo '<div class="accordion" id="courseAccordion">';
        while ($course = mysqli_fetch_assoc($courses_result)) {
            echo '<div class="accordion-item">
                    <h2 class="accordion-header" id="heading' . $course['c_code'] . '">
                        <button class="accordion-button collapsed" type="button" data-bs-toggle="collapse" data-bs-target="#collapse' . $course['c_code'] . '">
                            ' . $course['c_code'] . ' - ' . $course['c_name'] . '
                        </button>
                    </h2>
                    <div id="collapse' . $course['c_code'] . '" class="accordion-collapse collapse">
                        <div class="accordion-body">
                            <form method="POST" action="editcourse.php">
                                <input type="hidden" name="c_code" value="' . $course['c_code'] . '">
                                <div class="mb-2">
                                    <label class="form-label">Course Name:</label>
                                    <input type="text" name="c_name" class="form-control" value="' . $course['c_name'] . '" required>
                                </div>
                                <div class="mb-2">
                                    <label class="form-label">Credit Hours:</label>
                                    <input type="number" name="c_credit" class="form-control" value="' . $course['c_credit'] . '" required>
                                </div>
                                <div class="mb-2">
                                    <label class="form-label">Lecturer:</label>
                                    <input type="text" name="c_lec" class="form-control" value="' . $course['c_lec'] . '" required>
                                </div>
                                <div class="mb-2">
                                    <label class="form-label">Max Students:</label>
                                    <input type="number" name="c_max" class="form-control" value="' . $course['c_max'] . '" required>
                                </div>
                                <button type="submit" class="btn btn-primary">Save Changes</button>
                                <button type="reset" class="btn btn-warning" id="clearForm">Clear Form</button>
                                <button type="submit" class="btn btn-danger" name="delete_course" onclick="return confirm(\'Are you sure you want to delete this course?\')">Delete Course</button>
                            </form>
                        </div>
                    </div>
                  </div>';
        }
        echo '</div>'; 
    } else {
        echo '<p class="mt-3 text-danger">No courses available for this semester.</p>';
    }
    exit();
}

include 'headeradmin.php';

// Fetch available semesters for dropdown
$semesters_query = "SELECT DISTINCT c_sem FROM tb_course ORDER BY c_sem DESC";
$semesters_result = mysqli_query($con, $semesters_query);
?>

<div class="container mt-4">
    <h2 class="mb-4">Edit Course</h2>
    <p class="text-secondary-emphasis" style="font-style: italic; font-weight: bold;">Admin may edit, update, or delete courses here.</p>

    <!-- Display success or deletion messages -->
    <?php if (isset($_GET['success'])) echo '<div class="alert alert-success">Course updated successfully!</div>'; ?>
    <?php if (isset($_GET['deleted'])) echo '<div class="alert alert-danger">Course deleted successfully!</div>'; ?>

    <label for="c_sem" class="form-label">Select Semester:</label>
    <select id="semester-select" class="form-select">
        <option value="">-- Choose Semester --</option>
        <?php while ($row = mysqli_fetch_assoc($semesters_result)) : ?>
            <option value="<?php echo $row['c_sem']; ?>"><?php echo $row['c_sem']; ?></option>
        <?php endwhile; ?>
    </select>

    <div id="courseAccordionContainer" class="mt-3"></div>
</div>

<script>
document.getElementById("semester-select").addEventListener("change", function() {
    let semester = this.value;
    let accordionContainer = document.getElementById("courseAccordionContainer");

    if (semester) {
        fetch("editcourse.php?fetch_courses=1&c_sem=" + semester)
        .then(response => response.text())
        .then(data => {
            accordionContainer.innerHTML = data.trim();
        })
        .catch(error => console.error("Error fetching courses:", error));
    } else {
        accordionContainer.innerHTML = "";
    }
});

// Ensure form reset works
document.addEventListener("DOMContentLoaded", function() {
    document.querySelectorAll("form").forEach(form => {
        form.addEventListener("reset", function() {
            setTimeout(() => {
                form.querySelectorAll("input").forEach(input => input.value = input.defaultValue);
            }, 0);
        });
    });
});
</script>

<div class="footer mt-4">
    <p>CRS developed by Adriana @ 2024</p>
</div>

<?php include 'footer.php'; ?>
