# Parallel Image Processing

- **Activity:** Multithreaded Java Computing Through Parallel Image Processing
- **Type:** Plugged
- **Course:** CS2
- **Estimated time:** Two 85-minute class sessions
- **PDC topics:** data parallelism, multithreading, speedup, limits of speedup, synchronization, race conditions, load balancing, and performance evaluation
- **Related e-book materials:** CS2, `chapter18-MSU`

## Overview

This activity uses image processing to introduce parallel and distributed computing concepts in CS2. During the first class session, students learn the relevant concepts through lecture slides, sample programs, and demonstrations. During the second session, students complete the programming lab, conduct performance experiments, and discuss their results.

## Included Materials

| File | Purpose |
| --- | --- |
| `PDC_slides.key` | Lecture slides introducing the PDC concepts and Java techniques used in the activity. |
| `PDC_sample_GUI.zip` | Demonstrates the execution-time differences between sequential processing and parallel processing with different numbers of threads. It is also used to illustrate the limits of speedup as additional threads are introduced. |
| `Histogram_Sample.zip` | Demonstrates synchronization through parallel histogram generation. Students can compare unsynchronized and synchronized implementations and observe the effects of race conditions on shared data. |
| `Edge_Detection_Sample.zip` | Demonstrates how to implement multithreading in Java using an image edge-detection task. |
| `CSIT 112 PDC Lab Instruction.pdf` | Student-facing instructions for the parallel image-processing lab. |
| `PDC_lab.zip` | Starter code and supporting files for completing the lab assignment. |

## Implementation Notes

The distributed packages intentionally do not include input images. Before running the sample programs or completing the lab, instructors or students should add their own images to the appropriate `images/input` directory. They should use images they created themselves or images for which they have permission to copy, modify, and use in the activity.

For timing experiments, instructors should process a batch of sufficiently large images rather than a single image. A single image may complete too quickly to reveal meaningful differences among sequential execution and parallel execution with different thread counts. In our implementation, a batch of 15 images of approximately 11 MB each produced observable timing differences. The exact number and size may be adjusted for the available computers. Students should compare measured execution times, calculate or discuss speedup, and consider why increasing the number of threads does not produce unlimited performance improvement.

The histogram example should be used to contrast unsynchronized and synchronized access to shared data. The edge-detection example then provides a concrete model for partitioning image-processing work among multiple Java threads before students begin the lab assignment.
