# CS210
Repository for CS-210 Code

Summarize the project and what problem it was solving.

  In this project, we were to perform analysis of a store inventory text file. To do this, we were to create a command line user interface with C++ and manipulate  the data with Python. 

What did you do particularly well?

  I was able to take the Python / C++ wrapper provided by the professor and abstract it into a header / specific C++ file for defining its functionality. 

Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?

  I believe my code could be more efficient by instantiating the Python item dictionary only once before making menu selections. In the current implementation, every time a menu selection is made, a new instance of the data dictionary is created.

Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?

  The most challenging part was getting Python to read the text file. I had to collaborate with peers to figure out how to use the OS module to point Python to the current working directory and open the file in the current working directyory with an absolute path.

What skills from this project will be particularly transferable to other projects or course work?

  I feel the portions of utilizing post build events to place Python scripts in the output file so they can be accessed provided me with a greater understanding of how C++ works and how it integrates with Python. I think this will provide me with useful skills for the future for interacting with other types of frameworks.

How did you make this program maintainable, readable, and adaptable?

  By creating a class for items sold and by abstracting the Python interface into its own header / C++ file, I feel I made this more readable and / or adaptable. By dedicating a class to these I will easily be able to expand on their functionality without changing huge parts of my existing code.

