# Flag Maker

- **Activity:** Flag Maker
- **Type:** Unplugged
- **Course:** CS1
- **Estimated time:** 85 minutes
- **PDC topics:** Data parallelism and parallel animation
- **Main files:** `CS1_MSU_FlagMaker_slides.pptx`
- **Related e-book section:** 10.3.1

## Implementation Details

The Flag Maker activity was implemented as a guided in-class unplugged exercise. The instructor used lecture slides to lead students through the activity sequence and to introduce the related PDC concepts after each scenario. The activity began with a pre-activity quiz, which was administered before any PDC concepts were introduced. After the activity, students completed a post-activity quiz with the same questions, followed by a short feedback survey about the Flag Maker activity.

During the activity, students were organized into groups of different sizes depending on the scenario. For the single-processor scenario, each group included one student acting as the processor and one student acting as the timer. For the two-processor and four-processor scenarios, additional students were assigned as processors according to the task-partitioning strategy. Each group received printed flag grids and crayons. The student responsible for timing used their own phone as a stopwatch.

Each group was assigned a group number. After each scenario, the instructor recorded the completion time for each group on the whiteboard. This allowed the class to compare the time costs across groups and across different processor configurations. The timing results were mainly used to support discussion of sequential execution, parallel execution, speedup, scalability, and load balancing.

The instructor then used the follow-up questions and explanation slides to connect each scenario to additional PDC concepts. Scenario 1 supported discussion of sequential processing and single-processor bottlenecks. Scenario 2 introduced task division and possible race conditions when processors are assigned overlapping work. Scenario 3 supported discussion of speedup, scalability, synchronization, and idle time caused by load imbalance. Scenario 4 introduced an alternative column-based partitioning strategy and was used to discuss boundary management, contention for shared resources, dependencies, distributed task partitioning, and pipelining.

The activity concluded with browser-based animations that reinforced the concepts demonstrated in the unplugged exercise. The animations helped connect the physical coloring task to computational models of parallel execution and provided a visual bridge between the classroom activity and PDC terminology.
