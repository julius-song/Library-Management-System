# Library Management System

A simple yet functional library management system.

## Introduction

8 functions are implemented in this system:

1. Adding items.
    * Add a book item with its title, author, date of purchase, price, type(A,B,C), and index number.
2. Traverse items.
    * Traverse all items stored in the system.
3. Search items.
    * Search a certain item(s) on key fields such as title, author, date of purchase, type(A,B,C), and index number.
4. Sort items.
    * Sort all items in ascending/descending order on key fields such as title, author, date of purchase, price, type(A,B,C), and index number.
5. Delete items.
    * Delete an item according to its index number.
6. Revise items.
    * Revise a certain fields of an itme based on its index number.
7. Import from files.
    * Import items from .txt files.
8. Export to files.
    * Export items to .txt files.

*This project is a course project of Data Structure & Algorithm Design (Spring 2017)*

## Usage

Run **Library_Management_System.cpp** entering the main menu, follow all instructions accordingly.

```
*******************************************************************
Input a Number to Take Actions:
1:Add Book Items	2:Traverse Book Items	3:Search Book Items
4:Sort Book Items	5:Delete Book Items	6:Revise Library
7:Import from Files	8:Export to Files	0:Exit System
*******************************************************************
```

Add items:

```
#Add Book Items#
Please Input Information of the Books to Be Added in Following Order:
Title, Author, Date of Purchase, Price, Type(A,B,C), Index Number.
Example:Davinci_Code Dan_Brown 2017 04 25 50.05 A 23

**Space Should be Replaced by "_", Part Each Field with One Space.
**Index Number is the Unique Identification of Each Book Item, Hence It Cannot be Revised, and Should Not be Distributed to More Than One Item.
```

Search items:

```
#Search Book Items#

What Field does the Searching Keyword Belong To? Please Input a Number:
1:Title   2:Author   3:Type   4:Index Number   5:Date of Purchase
```

Sort items:

```
#Sort Book Items#

With Which Field Do You Intend to Sort? Please Input a Number:
1:Title   2:Author   3:Date of Purchase   4:Price   5:Type   6:Index Number

In Which Order Do You Prefer to Sort? Please Input a Number:
1: Ascending Order	2: Descending Order
```

Import from files:

```
#Import Items from Files#

Please Input the Name of the File to be Imported in Current Directory.
Eg: Library.txt
```

Export to files:

```
#Export Items to Files#
Please Input the Name of the File to Export All Items to, Eg: Library.txt
**If Such File Does not Exist in Current Directory, It Will be Created.
```

## Authors

* **Junlin Song** - *Initial work* - [julius-song](https://github.com/julius-song)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
