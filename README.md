# Expenses-Tracker
This is an app to keep track of your expenses in a month

This is a simple console-based application written in C++, which allows users to store and manage their transactions for a month. 
Users can modify transactions, view monthly spending, delete transactions, and view transactions of a single type.

Installation:

1. Clone the repository from GitHub.
2. Install a C++ compiler if not already installed.
3. Compile and run the application using the command prompt or an IDE of your choice.

Usage:

The application starts by displaying a menu of options:

-----------------------------------------
1. Add Transaction
2. Modify Transaction
3. Show Transactions
4. Delete Transaction
5. Filter Transactions
6. Sum of Type
7. Reset All
8. Close Console
-----------------------------------------

Users can choose an option by entering a number between 1 and 8. The application will prompt the user for additional information if necessary.

1. Adding a Transaction:

To add a Transaction select 1 from menu. You will be asked for a description (ex. "Food"), a type (ex. "in" or "out"), a sum (ex. 100), a day (ex. 19).

2. Modify Transaction:

To modify a Transaction select 2 from menu. You will be asked for the ID of the transaction. Then, you will have to choose from the following menu:

-----------------------------------------
1. Type
2. Description
3. Sum
4. Go Back
-----------------------------------------
Select one number then write the new parameter.

3. Show Transactions:

To show all Transactions select 3 from menu. A list of Transactions will appear on console in the following order: description, type, sum, day.

ex: food out 100 19
drinks out 55 10
salary in 2000 15

4. Delete Transaction:

To delete a Transaction select 4 from menu. You will be asked for the ID of the transaction.

5. Filter Transactions:

To filter your Transactions select 5 from menu. You will be asked to filter by type or description. For type you can choose between "in" and "out", but for description
you can choose whatever you want, which you will be asked after selecting "type" or "description".

6. Sum of Type:

To show how much you earned or spend select 6 from menu. You will be asked for the type, which is "in" or "out".

7. Reset All:

To reset all select 7 from menu. Every transaction will be deleted and you will have a fresh start.

8. Close Console:

Select 8 from menu when you're done.

Contributions:

Contributions are welcome! If you find a bug or want to suggest a new feature, please submit a pull request or open an issue on GitHub.
