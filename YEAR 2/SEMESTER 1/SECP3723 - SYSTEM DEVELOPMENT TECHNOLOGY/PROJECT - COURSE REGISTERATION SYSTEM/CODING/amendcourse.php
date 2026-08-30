<?php
include('crssession.php');
if (!session_id()) {
    session_start();
}
include 'headeradmin.php';
include 'db_connect.php'; // Ensure database connection

// Handle Amend Registration (AJAX request)
if ($_SERVER['REQUEST_METHOD'] == 'POST' && isset($_POST['ajax_update'])) {
    include 'db_connect.php'; // Ensure the database connection is included

    $r_tid = mysqli_real_escape_string($con, $_POST['r_tid']);
    $new_course = mysqli_real_escape_string($con, $_POST['new_course']);

    $update_sql = "UPDATE tb_registration SET r_course = '$new_course' WHERE r_tid = '$r_tid'";

    if (mysqli_query($con, $update_sql)) {
        // Fetch the updated course name
        $course_sql = "SELECT c_name FROM tb_course WHERE c_code = '$new_course'";
        $course_result = mysqli_query($con, $course_sql);

        if ($course_result) {
            $course_name = mysqli_fetch_assoc($course_result)['c_name'];
            echo json_encode(["status" => "success", "course_name" => $course_name]);
        } else {
            echo json_encode(["status" => "error", "message" => "Failed to fetch course name"]);
        }
    } else {
        echo json_encode(["status" => "error", "message" => mysqli_error($con)]);
    }
    exit;
}

// Handle Cancel Registration
if (isset($_GET['delete'])) {
    $r_tid = mysqli_real_escape_string($con, $_GET['delete']);
    $selected_semester = mysqli_real_escape_string($con, $_GET['semester']); // Keep the selected semester
    $delete_sql = "DELETE FROM tb_registration WHERE r_tid = '$r_tid'";

    if (mysqli_query($con, $delete_sql)) {
        echo "<script>alert('Registration cancelled successfully'); window.location.href='amendcourse.php?semester=$selected_semester';</script>";
    } else {
        echo "<script>alert('Error cancelling registration');</script>";
    }
}

// Fetch available semesters
$semesters_query = "SELECT DISTINCT r_sem FROM tb_registration ORDER BY r_sem DESC";
$semesters_result = mysqli_query($con, $semesters_query);

// Get selected semester from URL
$selected_semester = isset($_GET['semester']) ? $_GET['semester'] : '';

// Fetch registered students based on selected semester
$registrations = [];
if ($selected_semester) {
    $sql = "SELECT r.r_tid, r.r_student, r.r_course, c.c_name 
            FROM tb_registration r 
            JOIN tb_course c ON r.r_course = c.c_code 
            WHERE r.r_sem = '$selected_semester'";
    $registrations = mysqli_query($con, $sql);
}
?>

<div class="container"><br>
    <h2>Amend or Cancel Registration</h2>
    <p class="text-secondary-emphasis" style="font-style: italic; font-weight: bold;">Admin may amend or delete course registration here.</p>
    <!-- Select Semester Dropdown -->
    <form method="GET" action="amendcourse.php">
    <label for="semester-select" class="form-label">Select Semester:</label>
    <select id="semester-select" name="semester" class="form-select" onchange="this.form.submit()">
        <option value="">-- Choose Semester --</option>
        <?php while ($row = mysqli_fetch_assoc($semesters_result)) : ?>
            <option value="<?php echo $row['r_sem']; ?>" <?php echo ($row['r_sem'] == $selected_semester) ? 'selected' : ''; ?>>
                <?php echo $row['r_sem']; ?>
            </option>
        <?php endwhile; ?>
    </select>
    </form>

    <!-- Table for Registrations -->
    <?php if ($selected_semester && mysqli_num_rows($registrations) > 0) : ?>
        <table class="table table-bordered mt-3">
            <thead>
                <tr>
                    <th>Student ID</th>
                    <th>Course Name</th>
                    <th>Amend To</th>
                    <th>Cancel</th>
                </tr>
            </thead>
            <tbody>
                <?php while ($row = mysqli_fetch_assoc($registrations)) { ?>
                <tr id="row-<?php echo $row['r_tid']; ?>">
                    <td><?php echo htmlspecialchars($row['r_student']); ?></td>
                    <td id="course-name-<?php echo $row['r_tid']; ?>"><?php echo htmlspecialchars($row['c_name']); ?></td>
                    <td>
                        <select name="new_course" class="form-select course-select" data-id="<?php echo $row['r_tid']; ?>">
                            <?php
                            // Fetch available courses for the selected semester
                            $courses_sql = "SELECT c_code, c_name FROM tb_course WHERE c_sem = '$selected_semester'";
                            $courses_result = mysqli_query($con, $courses_sql);
                            while ($course = mysqli_fetch_assoc($courses_result)) {
                                $selected = ($course['c_code'] == $row['r_course']) ? 'selected' : '';
                                echo "<option value='{$course['c_code']}' $selected>{$course['c_name']}</option>";
                            }
                            ?>
                        </select>
                        <button type="submit" class="btn btn-primary btn-sm mt-1 update-btn" data-id="<?php echo $row['r_tid']; ?>" onclick="return confirm('Amendment succesful, refresh the page!');">Update</button>
                    </td>
                    <td>
                        <a href="amendcourse.php?delete=<?php echo $row['r_tid']; ?>&semester=<?php echo $selected_semester; ?>" class="btn btn-danger btn-sm" onclick="return confirm('Are you sure?');">Cancel</a>
                    </td>
                </tr>
                <?php } ?>
            </tbody>
        </table>
    <?php elseif ($selected_semester) : ?>
        <p class="mt-3 text-danger">No registrations found for this semester.</p>
    <?php endif; ?>
</div>

<div class="footer">
    <p>CRS developed by Adriana @ 2024</p>
</div>

<?php include 'footer.php'; ?>

<!-- jQuery for AJAX -->
<script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
<script>
$(document).ready(function(){
    $(".update-btn").click(function(){
        var rowId = $(this).data("id");
        var newCourse = $("#row-" + rowId + " select[name='new_course']").val();
        var semester = $("#semester-select").val();

        $.ajax({
            type: "POST",
            url: "amendcourse.php",
            data: { ajax_update: true, r_tid: rowId, new_course: newCourse, semester: semester },
            dataType: "json",
            success: function(response) {
                if (response.status === "success") {
                    // Update course name in the table for the affected row
                    $("#course-name-" + rowId).text(response.course_name);

                    // Automatically reload the page to reflect changes
                    location.reload();
                } else {
                    alert("Error updating registration: " + response.message);
                }
            },
            error: function() {
                alert("AJAX error: " + xhr.responseText);
            }
        });
    });
});
</script>
