Flag Coloring Unplugged Activity
================================

Sample flag grids for this activity are available in the **"unplugged activity"** folder. Two example flags are provided:

- **Netherlands Flag** – A simple introductory exercise.
- **Canada Flag** – A more challenging activity with additional regions and dependencies.

Objective
---------
This unplugged activity introduces students to fundamental Parallel and Distributed Computing (PDC) concepts, including task decomposition, concurrency, synchronization, workload balance, and communication overhead.

Materials
---------
- Printed flag grid (Netherlands or Canada)
- Grid paper (one sheet per student or group)
- Three colored markers (red, blue, and black or other contrasting colors)

Instructions
------------
1. Give each student (or group) a printed flag grid and a sheet of grid paper.
2. Students should recreate the flag by coloring the grid **one cell (pixel) at a time**.
3. **Students may only place individual dots (pixels).** They are **not allowed to draw lines or fill entire regions.** This imitates how digital images are represented as collections of pixels.
4. Start with the Netherlands flag for practice since it contains only three horizontal regions.
5. After students understand the process, repeat the activity using the Canada flag, which requires more careful planning and coordination.

Suggested Variations
--------------------
Individual Activity
- One student colors the entire flag sequentially.
- Record the completion time.

Parallel Activity
- Divide the class into small groups.
- Assign each student responsibility for different portions of the flag.
- Students work simultaneously while ensuring that neighboring regions are colored correctly.
- Record the completion time and compare it with the sequential version.

Discussion Questions
--------------------
After completing the activity, discuss the following questions:

- Which parts of the flag could be colored independently?
- Which regions required communication or coordination?
- Did adding more students always reduce the completion time?
- Was the workload evenly distributed among all students?
- What overhead was introduced by coordinating multiple people?
- How is this activity similar to parallel image processing or graphics rendering?

Learning Outcomes
-----------------
After completing this activity, students should be able to:

- Explain the difference between sequential and parallel execution.
- Recognize opportunities for task decomposition.
- Understand why some tasks can execute concurrently while others require synchronization.
- Describe the effects of workload imbalance and communication overhead.
- Relate the activity to pixel-based image processing and parallel computing applications.

Instructor Notes
----------------
- The Netherlands flag typically requires approximately **10–15 minutes**.
- The Canada flag typically requires approximately **20–30 minutes**, depending on class size and discussion.
- Encourage students to think about how they would divide the work before they begin coloring.
- This activity works well as an introduction to parallel image processing, OpenMP, or GPU rendering because each colored dot represents a single pixel.
- The goal is not artistic accuracy but understanding how a large problem can be decomposed into many small, independent tasks.