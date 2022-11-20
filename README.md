# Automated Sentence Generator 👨‍💻 ‍💻 📚

### All of the trouble we went through was worth it in the end since we are now able to present a completely working program.

![Capture d’écran 2022-11-20 163734](https://user-images.githubusercontent.com/62343240/202911195-a1ea964c-cdbd-401f-9c3c-7ad4724b052f.png)

<!-- INTRODUCTION -->

## Introduction

In our algorithm course, we studied binary trees. In the continuity of our course and to apply the knowledge we have just learned, we have done the Automated Sentence Generator project in C.

The goal of this project is to automatically generate sentences that are grammatically and orthographically correct, but do not necessarily make sense. This program is similar to the game called Cadavre Exquis.

First of all, we had to build our structure in order to facilitate the insertion and the construction of words in a tree. Then, with a search function (inflected form or basic form), we went through the tree from letter to letter or from node to node to search for the desired word. The database of words was in a file containing 300 000 words without accents from which we had to extract. Then, from the stack of words, we build sentences. To create this data structure, we need to arrange the words according to their types (noun, verb, adjective, adverb). Then we need to label the words in gender and number, and specify in which tense the verbs are conjugated.

## Run the program

- To run the program, you can write the following command :
  ```sh
  ./Test.exe
  ```

<p align="right">(<a href="#top">retourner en haut de la page</a>)</p>



