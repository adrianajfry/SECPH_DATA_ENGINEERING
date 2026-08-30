<?php 
include('crssession.php');
if(!session_id()) {
  session_start();
}
include 'headerstudent.php';
include 'db_connect.php';

// Fetch distinct semesters from tb_course
$semester_query = "SELECT DISTINCT c_sem FROM tb_course";
$semester_result = mysqli_query($con, $semester_query);

// Fetch all courses grouped by semester
$courses_by_semester = [];
$course_query = "SELECT c_code, c_name, c_sem FROM tb_course";
$course_result = mysqli_query($con, $course_query);
while ($row = mysqli_fetch_assoc($course_result)) {
    $courses_by_semester[$row['c_sem']][] = $row; // Group courses by semester
}
?>

<div class="container"> 
  <br><br><br>

  <!-- Title and Search Bar Inline -->
  <div class="d-flex justify-content-between align-items-center">
    <h4 class="mb-0">Course Registration Form</h4>
    <div class="position-relative">
      <form class="d-flex" id="searchForm">
        <input class="form-control form-control-sm me-2" type="search" placeholder="Search courses" id="courseSearch">
        <button class="btn btn-pink btn-sm" type="button" id="searchBtn">Search</button>
      </form>
      <!-- Search results dropdown -->
      <ul id="searchResults" class="list-group position-absolute w-100" style="z-index: 1000; display: none;"></ul>
    </div>
  </div>
  
  <!-- Alert Message Placeholder -->
  <div id="alertMessage">
    <?php 
    if (isset($_SESSION['warning_message'])) {
        echo '<div class="alert alert-dismissible alert-warning">
                <button type="button" class="btn-close" data-bs-dismiss="alert"></button>
                <h2 class="alert-heading">Warning!</h2>
                <p class="mb-0">' . $_SESSION['warning_message'] . '</p>
              </div>';
        unset($_SESSION['warning_message']); // Clear the message after displaying
    }
    ?>
</div>

  <form method="POST" action="courseregisterprocess.php">
    <fieldset>
      
      <!-- Semester Selection -->
      <div>
        <label for="semesterSelect" class="form-label mt-4">Please select current semester</label>
        <select class="form-select" name="fsem" id="semesterSelect" required>
          <option value="">Select semester</option>
          <?php
          while ($row = mysqli_fetch_assoc($semester_result)) {
            echo "<option value='" . htmlspecialchars($row['c_sem']) . "'>" . htmlspecialchars($row['c_sem']) . "</option>";
          }
          ?>
        </select>
      </div>

      <!-- Course Selection -->
      <div>
        <label for="courseSelect" class="form-label mt-4">Please select an available course</label>
        <select class="form-select" name="fcourse" id="courseSelect" required>
          <option value="">Select a semester first</option>
        </select>
      </div>
      
      <br>
      <button type="submit" class="btn btn-primary">Register</button>
      <button type="reset" class="btn btn-warning">Clear Form</button>
      <br><br><br>

    </fieldset>
  </form>
</div><br>

<div class="footer">
  <p>CRS developed by Adriana @ 2024</p>
</div>

<script>
document.getElementById('semesterSelect').addEventListener('change', function() {
    let semester = this.value;
    let courseSelect = document.getElementById('courseSelect');
    let courseSearch = document.getElementById('courseSearch');

    courseSelect.innerHTML = "<option value=''>Select a semester first</option>"; // Reset dropdown
    courseSearch.value = ""; // Clear search input
    courseSearch.disabled = (semester === ""); // Enable search only when a semester is selected

    if (semester === "") return; // Stop if no semester is selected

    // Courses data embedded in PHP
    let coursesBySemester = <?php echo json_encode($courses_by_semester); ?>;
    
    if (coursesBySemester[semester]) {
        coursesBySemester[semester].forEach(course => {
            let option = document.createElement('option');
            option.value = course.c_code;
            option.textContent = course.c_code + " - " + course.c_name;
            courseSelect.appendChild(option);
        });
    } else {
        courseSelect.innerHTML = "<option value=''>No courses available</option>";
    }
});

// Search button click handler
document.getElementById('searchBtn').addEventListener('click', function() {
    let searchValue = document.getElementById('courseSearch').value.toLowerCase();
    let coursesBySemester = <?php echo json_encode($courses_by_semester); ?>;
    let matchedCourses = [];
    let courseFound = false; // Flag to track if any course matches

    // Loop through courses and match search input
    for (let semester in coursesBySemester) {
        coursesBySemester[semester].forEach(course => {
            let courseText = (course.c_code + " - " + course.c_name).toLowerCase();
            if (courseText.includes(searchValue)) {
                matchedCourses.push({ code: course.c_code, name: course.c_name, semester: semester });
                courseFound = true; // Set flag to true if a match is found
            }
        });
    }

    // Display alert if no courses match the search
    let alertMessage = document.getElementById('alertMessage');
    alertMessage.innerHTML = ''; // Clear any previous alerts

    if (searchValue !== "" && !courseFound) {
        let alert = document.createElement('div');
        alert.className = "alert alert-dismissible alert-danger";
        alert.innerHTML = `<button type="button" class="btn-close" data-bs-dismiss="alert"></button>
                          <strong>Oh snap!</strong> The course is not available.`;

        alertMessage.appendChild(alert);
    }

    // Display matched courses in dropdown
    let searchResults = document.getElementById('searchResults');
    searchResults.innerHTML = ""; // Clear previous results
    searchResults.style.display = "none"; // Hide results initially

    if (matchedCourses.length > 0) {
        searchResults.style.display = "block";
        matchedCourses.forEach(course => {
            let listItem = document.createElement('li');
            listItem.className = "list-group-item list-group-item-action";
            listItem.textContent = course.code + " - " + course.name;
            listItem.dataset.courseCode = course.code;
            listItem.dataset.courseName = course.name;
            listItem.dataset.courseSemester = course.semester;
            
            listItem.addEventListener('click', function() {
                document.getElementById('courseSearch').value = this.textContent;
                document.getElementById('semesterSelect').value = this.dataset.courseSemester;
                document.getElementById('semesterSelect').dispatchEvent(new Event('change'));

                // Auto-select course in dropdown if available
                setTimeout(() => {
                    document.getElementById('courseSelect').value = this.dataset.courseCode;
                }, 200);
                
                searchResults.style.display = "none"; // Hide results after selection
            });

            searchResults.appendChild(listItem);
        });
    }
});

// Hide search results if clicked outside
document.addEventListener('click', function(event) {
    let searchBox = document.getElementById('courseSearch');
    let searchResults = document.getElementById('searchResults');

    if (!searchBox.contains(event.target) && !searchResults.contains(event.target)) {
        searchResults.style.display = "none";
    }
});

// Create a new <style> element
let style = document.createElement('style');
style.innerHTML = `
    .btn-pink {
        background-color: lightpink; /* Hot Pink */
        border-color: #ff69b4;
        color: white;
    }
    .btn-pink:hover {
        background-color: pink; /* Deep Pink */
        border-color: #ff1493;
    }
`;
document.head.appendChild(style); // Append to <head>

// Change button class to apply the new style
document.addEventListener("DOMContentLoaded", function() {
    let searchBtn = document.querySelector(".btn-secondary");
    if (searchBtn) {
        searchBtn.classList.remove("btn-secondary");
        searchBtn.classList.add("btn-pink");
    }
});
</script>

<?php include 'footer.php'; ?>