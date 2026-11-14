# Chapter 16 — Integrating Parallel and Distributed Computing into CS2 with Python

**Xiaoyuan Suo · Webster University**

This directory contains instructional materials for introducing parallel and distributed computing (PDC) in a Python-based CS2 course. Three modules connect foundational parallel programming concepts with image processing and introductory performance engineering. Instructors may adopt the complete sequence or select activities that fit an existing course.

The emphasis is on understanding how work is divided, how workers coordinate, and why a correct parallel program may or may not run faster. Python provides an accessible environment for experimentation; performance results are part of the investigation rather than a promised outcome.

## Start here

1. Review the course organization in `Detailed_Pre_and_Post_Syllabus` and identify where the activities fit your syllabus.
2. Read the module-specific `readme.md` or read-me PDF before selecting slides, examples, and assignments.
3. Extract the sample-program ZIP files and run the selected examples in the environment students will use.
4. Choose an adoption path below and adjust input sizes, worker counts, and assignment expectations for your students.

## Audience and prerequisites

These materials are intended for students who already understand basic Python syntax, conditionals, loops, functions, and common data structures such as lists. Familiarity with file handling and basic debugging is useful. Introduce any image-processing libraries and array operations needed for the selected examples before assigning independent work.

Prior parallel programming experience is not required. An HPC cluster is optional: a multicore computer can support the introductory experiments. Cluster-specific access and job-submission instruction can be added when appropriate.

## Suggested adoption paths

| Path | Recommended sequence | Instructional emphasis |
| --- | --- | --- |
| Brief introduction | Selected Module 1 examples followed by a small timing comparison from Module 3 | Divide a task, execute it with multiple workers, and explain overhead. |
| Application-focused integration | Essential Module 1 concepts → Module 2 image-processing activity → selected Module 3 measurements | Connect decomposition to a visible application and evaluate the result. |
| Performance-focused integration | A provided sequential/parallel example → Module 3; revisit Module 1 as needed | Compare implementations, measure consistently, and explain bottlenecks. |
| Complete sequence | Module 1 → Module 2 → Module 3 | Build from parallel concepts to applications and evidence-based performance analysis. |

These are suggested routes, not fixed lesson schedules. Instructors can use short demonstrations, guided laboratories, or longer projects depending on available time. For students with limited experience, provide complete runnable code and ask them to predict, run, observe, modify a small input, and explain the result.

## File organization

The tables below describe the folders and visible files in this chapter's organization. Long filenames shortened in the folder view are described by purpose rather than reconstructed.

| Folder | Contents and purpose |
| --- | --- |
| `Detailed_Pre_and_Post_Syllabus` | Course syllabus material documenting course organization and the placement of PDC instruction. |
| `Evaluation_Data_and_Analysis` | Evaluation records, including `CS2 Data Inventory.docx` and survey data. Consult these materials for the scope and limitations of the evidence. |
| `Plugged_Activities/Module1:Basics_PDC` | Introductory PDC slides, sample programs, parallel-sum assignment, and module guidance. |
| `Plugged_Activities/Module2_Image_Processing` | Image-processing slides, assignment, example archives, and module guidance. |
| `Plugged_Activities/Module3: Performance_Engineering` | Introductory performance-engineering materials, overhead lab, plotting script, and module guidance. |

### Module 1: Basics of PDC

Use this module to introduce task decomposition, concurrency, worker coordination, and the need for synchronization. Connect the examples to race conditions, locks, and deadlock where appropriate. Distinguish processes from threads and parallel execution from simply starting multiple tasks.

| File | Use |
| --- | --- |
| `Python parallel.pdf` | Introductory instructional slides. |
| `PDC Sample Programs.zip` | Sample-program archive for demonstrations and guided experimentation. |
| `Assignment12_parallel_sum.pdf` | Parallel-sum programming assignment. |
| `Read me.pdf` and `readme.md` | Module-specific teaching and usage guidance. |

**Suggested activity:** compare sequential and parallel processing of the same collection of values. Ask students to identify each worker's portion, explain how partial results are combined, and predict when coordination costs could outweigh the benefit of additional workers.

### Module 2: Parallel image processing

Use image transformations to make data decomposition visible. Students can inspect both the output image and the execution time while exploring how an image is divided among workers.

| File | Use |
| --- | --- |
| `parallel image .pdf` | Image-processing instructional slides. |
| `Assignment Parallel Image blur.pdf` | Parallel image-blurring assignment. |
| `blur image.zip` | Image-blurring example archive. |
| `grey scale.zip` | Grayscale example archive. |
| `remove green.zip` | Color-channel transformation example archive. |
| `read me.pdf` | Module-specific guidance. |

**Suggested activity:** begin with a simple pixel or color-channel transformation, then investigate blurring. Blur requires neighboring pixels, so students should examine boundaries between image partitions and check for visible seams or halo artifacts. Discuss why additional boundary data or overlapping regions may be needed.

When comparing implementations, distinguish explicit Python loops, library-based vectorization, and multiprocessing. They perform work differently; adding processes does not automatically improve an already optimized library operation.

### Module 3: Introductory performance engineering

Use this module to shift attention from producing working code to measuring and explaining its behavior. Topics include benchmarking, speedup, efficiency, scalability, parallel overhead, and basic bottleneck analysis.

| File or material | Use |
| --- | --- |
| Basic Performance Engineering PDF | Introductory instructional material; refer to the folder for the complete filename. |
| `Parallel Overhead Lab.pdf` | Guided investigation of parallel overhead. |
| `Performance engineering notes.pdf` | Supporting conceptual notes. |
| `Performance Plot.py` | Python plotting script for performance visualization. |
| `read me.pdf` | Module-specific guidance. |

**Suggested activity:** hold the input constant, vary the number of workers, repeat each configuration, and plot runtime. Calculate speedup as sequential runtime divided by parallel runtime, and efficiency as speedup divided by the number of workers. Ask students to explain plateaus or slowdowns using their measurements.

## Running and adapting the examples

- Use Python 3 and follow the instructions accompanying each module. Install only the additional packages required by the selected programs.
- Extract each ZIP archive before running its contents. Check input-file locations and output paths.
- Test multiprocessing examples as standalone `.py` scripts when notebook execution causes problems. Preserve or add the `if __name__ == "__main__":` entry-point guard where required.
- Start with small inputs to check correctness, then increase the workload for timing experiments. Keep input data and output requirements consistent across comparisons.
- Record the computing environment, input size, and worker count. Available CPU resources may differ between student machines, hosted notebooks, and cluster allocations.
- Repeat timing trials and report a representative runtime together with variability. State whether process startup, data transfer, and file I/O are included in the measured interval.

## Assessment suggestions

Assess correctness and reasoning alongside code. A short submission can include the program, a small results table or plot, and concise explanations of:

1. How the work was divided and how results were combined.
2. How correctness was checked against a sequential implementation.
3. What changed as the input size or worker count changed.
4. Why performance improved, remained similar, or became worse.

For image processing, include a visual correctness check at partition boundaries. For performance experiments, assess the measurement method and explanation rather than rewarding the largest speedup. A well-explained slowdown is a useful result.

## Evaluation materials and interpretation

The `Evaluation_Data_and_Analysis` folder supports review of the instructional implementation. Begin with the data inventory to identify the courses, instruments, response counts, missing data, and matching or anonymization constraints relevant to each dataset.

Treat anonymous or unmatched pre- and post-survey responses as descriptive summaries of the responding groups. Differences in reported ratings do not establish individual learning gains or a causal effect of the modules. Report the applicable sample size with each summary and follow the documented IRB and anonymization constraints when reusing evaluation materials.

## Relationship to the book chapter

The chapter provides the instructional rationale, implementation experience, and discussion of evaluation evidence. This directory supplies the accompanying teaching resources. Read the chapter together with the module-specific guidance when adapting the materials for a different course, student population, or computing environment.
