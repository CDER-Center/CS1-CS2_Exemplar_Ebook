## Teaching Fork/Join in CS 2 (as done at Knox College) ##

This is material for teaching fork/join programming in a CS2 class.
I developed these materials for my use at Knox College, but they are heavily influenced by the work of Dan Grossman [1].
By way of context, Knox uses an academic calendar where each term is slightly less than 10 weeks.
The CS2 class meets 4 times a week, 3 lectures (MWF) and a lab (Th this term).
All class meetings are 70 minutes long.
This course uses Peer Instruction, a pedagogy where lecture is interrupted with multiple-choice questions.
The students answer these individually, then discuss them in groups and re-answer.
Then the instructor reveals the correct answer, has a student give an explanation of this answer, and then fills in any additional material.
These questions are graded only for participation.
Lab assignments aren't graded, but are used as a time for students to practice the material with the instructor and a TA available to answer questions.
(Variations of some lab problems are assigned as HW, which is graded.)

ForkJoin materials.  The slide deck (ForkJoin.pptx) has about 100 minutes of lecture introducing Java’s fork-join framework for parallel computing.
It introduces the idea using the notation from CLRS and then shows the (much messier) Java code.
The slides are in 1 deck; for class, I would add review and homework discussion slides to the beginning of each day, but I have removed these from the deck I’m sharing since they’ll vary by course and won’t fall in the same place (I add them each day based on where I get to in the previous lecture).
The comments on the slides flesh out what I’d say and explain the answers to the clicker questions.

Also related to these slides are the following:
* I've recorded myself lecturing from these slides over two class sessions: [lecture1](https://youtu.be/LO2cbi-M7jI) and [lecture2](https://youtu.be/pQ3PQY4viXA).
I'm using slightly older slides so the content doesn't exactly match the slides.

* Materials for lab8, which asks students to parallel a prime counting routine.
lab8.tex is a LaTeX version of handout (compile with course.sty), lab8.pdf is a pdf version of handout, lab8given.zip is a VS Code project with the given code.
The lab is basically one step up from the summing code we do in class (they are parallelizing a different operation over a range of indices).
Prime testing is just checking 3 to sqrt(n) as possible divisors (I only check odd numbers).  I’ve used this in class and feel that it works pretty well.
* Materials for lab9 (lab9.tex, lab9.pdf, lab9given.zip), which asks the students to change the code for summing an array in parallel to implement some other reductions.  I’ve only given it once.  Students struggled to implement finding the kth smallest value in this framework.  I have plans to revise the lab to address the issue.  I think this lab is less interesting/important than lab8 so I’d skip it if you’re only doing one.  (Alternatively, they could be combined if your labs are more substantial and are submitted for a grade.)
* A possible replacement lab (heatfork.tex, heatfork.pdf, heatSlides.pptx, heatDiffusionLab.zip). This asks the students to parallelize the heat diffusion simulator using fork and join.  I haven’t used it in this form, but have used the lab with Java threads and its Executor framework.  The slides are used in lecture the day before the lab to introduce the application (I also do a demo).

### References

[1] D. Grossman. Ready-For-Use: 3 Weeks of Parallelism and Concurrency in a Required Second-Year Data-Structures Course.
In Proc. Workshop on Curricula for Concurrency and Parallelism, 2010.