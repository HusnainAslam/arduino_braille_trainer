# Braille Trainer

## Outline
- Problem
- Introduction
- What is Braille
- Selected Approach

## Problem

The task is to develop a training application for braille using an Arduino. Connect a display as well as 6 buttons to the Arduino. The buttons will be arranged in a 2x3 grid representing one braille letter. The display will present a letter which has to be entered using the braille keyboard by pressing the right set of buttons at the same time. The display shows the results (right vs. wrong). Think of a score system (e.g. the trainee has n lives before the game ends and gets points for each correct letter).<br/>
![Braille Combinations](images/braille_comb.jpg)<br/>

## Introduction
Braille is a tactile reading and writing system, mainly used by blind people and those who are visually impaired. Raised dots are used to represent letters of the alphabet, punctuation, music, and even mathematical and scientific symbols.

Contrary to popular belief, braille is not its own language but rather an alternative set of symbols, like a code. Because of this, braille can be developed for any language.

## Why do we use Braille?
__[According to the NHS](https://www.nhs.uk/conditions/vision-loss/)__, there are almost 2 million people in the UK who suffer from sight loss; of this, 360,000 are registered as blind or partially sighted. And yet, there are only around 12,000 people in the UK who read braille.

One of the biggest myths when it comes to learning braille is that it will be too hard, but the truth is it doesn’t have to be. Most people who suffer from visual impairment have had it develop later in life, so learning a new “language” can seem pointless, especially with advances in technology. However, this simply isn’t the case


## Methodology
Braille Trainer consist of 3 Major parts along with it’s other components and these components interact with each other accordingly the given instruction. 

On start LCD will Display Welcome Statement or Game start statement
LCD will display any alphabetic letter on screen like Z,A,C,D.
After Display of alphabetic letter user will insert the code of respective letter using button 6 buttons attach with it.
If user press the correct combinations of button display will show answer correct and 10 points will be given to user.
On wrong answers there will be 3 tries for user After three attempts game will be over
On game ending user will see the screen back to start position
User have n number of lives.


## Circuit Design
![Braille Circuit Design](images/braille_bb.jpg)<br/>


## Component Requirment
To develop whole system we need list of components given below

1. Arduino Uno With Complete Box
2. 6 Button Keyboard or only Buttons
3. LED/LCD Display with dimension of 16*2/16*1 with I2C Display
4. Wires
5. Breadboard
6. Resistors of 1k ohm or 3.9k ohm 


## References
[1]P. Duc, "React Framework: Concept and Implementation", Bachelor, Turku University Of Applied Sciences, 2020.<br>
[2]S. Aggarwal, "Modern Web-Development using ReactJS", Department of Information Technology, Northern India Engineering College, 2018.<br>
[3]N. Naim, "ReactJS: An Open-Source JavaScript Library for Front-end Development", Bachelor, Metropolia University of Applied Sciences, 2017.<br>
[4]E. Thorén, "Usage of Angular from developer’s perspective", Bachelor, Faculty of Computing, Blekinge Institute of Technology, 2017.<br>
[5]M. Sultan, "Angular and the Trending Frameworks of Mobile and Web-based Platform Technologies: A Comparative Analysis", Future Technologies Conference (FTC), 2017.<br>
[6]S. Ambulkar, "Angular JS", Phd, Department of CSE, GCOE, Amravati, India, 2016.<br>
[7]E. Wohlgethan, "Supporting Web Development Decisions by Comparing Three Major JavaScript Frameworks: Angular, React and Vue. js.", PhD, Hochschule für Angewandte Wissenschaften Hamburg, 2018.<br>
[8]R. Mohammadi, “Performance, and Efficiency based Comparison of Angular and React.” A case study of Single page application (SPA), ministry of Higher Education Herat University computer science facility. <br>
