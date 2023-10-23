# C-Structured_Data_Types
This repository focuses on a series of programming exercises that tackle various scenarios, each elaborated in the exercise descriptions. These exercises are designed to apply fundamental concepts of algorithms and coding in the C language, emphasizing the handling of structured data types.

## CASE 1
Solve the exercises outlined in sections a), b), c), d), and e) based on the problem description below.

We need to maintain information about the billing amount for the corporate clients of our company, along with additional details described below.

**1.1.** Declare the necessary data types to store information about the portfolio of corporate clients. When needed, use the "word" type.

**1.1.A.** Declare a data type "tCompany" to store information about a company. For each company, identified by its CIF (Tax Identification Code), we want to store the commercial name, the name and last name of the contact person in separate fields, their phone number, address, the total invoice amount in euros since the company was established, the number of orders served to the company during that time, and the start date of the business relationship.

**1.1.B.** Declare a data type "tClientPortfolio" and the necessary constants to store the total billed amount for each of the companies, with a maximum of 1000 companies. You can utilize the "tCompany" data type without redefining it.

**1.2.** Design an action to print the commercial name of the company with the most orders served.

**1.3.** Without designing any algorithms, declare the necessary variables without initializing them and make a call to the action from the previous step.

**1.4.** Design a function that returns the average invoiced amount per order for all orders served to all companies.

**1.5.** Without designing any algorithms, declare the necessary variables without initializing them and make a call to the function from the previous step.


## CASE 2
We need to create an algorithm that initially displays a menu of options. Depending on the selected option, the user can input course names and their respective students, list the introduced courses along with the number of students in each, list the students of a specific course, delete an introduced course along with its students, or exit.

Given the following type definitions:

- "student": A tuple consisting of DNI (ID), Name, First Name, Last Name, and Telephone.
- "course": A tuple comprising the Denomination and an array of students along with the number of students stored.
- "school": A tuple for storing courses along with the number of courses saved.
