#--------------#
# Dependencies #
#--------------#
import os


#-------------------------------------#
# Function Declarations / Definitions #
#-------------------------------------#

#---------------------------------------------------------------------------------------#
# Description: Builds a word count dictionary for a text file.                          #
# Input / Parameters: A string representing an absolute path to a text file.            #
# Output / Return: A dictionary containing each word from a text file and their         #
#                  relative frequency in the file.                                      #
#---------------------------------------------------------------------------------------#
def build_data_dict(input_file: str) -> dict:

    # Declarations
    data_dict = dict()

    # Read file
    with open(input_file) as file:
        while file.readline():
            temp = file.readline().strip().lower()

            # Iterate dictionary if key exists, create key if it doesn't
            if data_dict.get(temp):
                data_dict[temp] += 1
            else:
                data_dict[temp] = 1

    # Return dictionary
    return data_dict


#---------------------------------------------------------------------------------------#
# Description: Retrieves dictionary based on input file. Print each item in input file  #
#              and it's frequency.                                                      #
# Input / Parameters: No explicit parameters. Dependent function uses input file of     #
#                     items sold.                                                       #
# Output / Return: No explicit return. Prints list of items in file dictionary to the   #
#                  screen.                                                              #
#---------------------------------------------------------------------------------------#
def output_file_dict() -> None:

    # Declaration / Populate data
    input_file = os.getcwd() + os.path.sep + "CS210_Project_Three_Input_File.txt"
    file_dict = build_data_dict(input_file)

    # Output each item in dictionary and its frequency.
    print()
    for key, value in file_dict.items():
        print(f"{key.title()}: {value}")
    print()


#---------------------------------------------------------------------------------------#
# Description: Finds frequency of a user specified string in dictionary populated by    #
#              input file.                                                              #
# Input / Parameters: User specified string provided through C++.                       #
# Output / Return: Integer number of occurences of user specified string.               #
#---------------------------------------------------------------------------------------#
def output_word_freq(word: str) -> int:

    # Declarations / Populate data
    word = word.lower()
    input_file = os.getcwd() + os.path.sep + "CS210_Project_Three_Input_File.txt"
    file_dict = build_data_dict(input_file)

    # Returns frequency of word if a key exists in dictionary, else returns 0.
    if file_dict.get(word):
        return file_dict[word]
    else:
        return 0


#---------------------------------------------------------------------------------------#
# Description: Creates frequency file from input list of sales.                         #
# Input / Parameters: No explicit parameters. Dependent function uses input sales list. #
# Output / Return: No explicit return. Creates frequency file of items sold.            #
#---------------------------------------------------------------------------------------#
def write_data_file() -> None:

    # Declarations / Populate data
    input_file = os.getcwd() + os.path.sep + "CS210_Project_Three_Input_File.txt"
    file_dict = build_data_dict(input_file)
    output_file = os.getcwd() + os.path.sep + "frequency.dat"

    # Write dictionary to output file 
    with open(output_file, "w") as file:
        for key, value in file_dict.items():
            file.write(key.title() + " " + str(value) + "\n")
        
