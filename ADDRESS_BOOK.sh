#!/bin/bash

ch=0;
while [[ ch -ne 5 ]]    
do
echo "1.Insert Record"
echo "2.View Address Book"
echo "3.Modify Record"
echo "4.Delete Record"
echo "5.Exit"

echo "Enter your choice:"
read ch
case $ch in
1)
echo "Enter Name:"
read name

echo "Enter Age:"
read age

echo "$name $age" | cat>>address_op
;;

2)
cat address_op
;;

3)
echo "Enter the Old Record:"
read rec1

echo "Enter New Record:"
read rec2

sed -i "s/$rec1/$rec2/" address_op
;;

4)
echo "Enter record to delete:"
read rec

sed -i "/$rec/d" address_op
;;

5)
echo "Exit"
;;

esac
done


*******************OUTPUT******************
sanika@sanika-VirtualBox:~$ bash ADDRESS_BOOK.sh
1.Insert Record
2.View Address Book
3.Modify Record
4.Delete Record
5.Exit
Enter your choice:
1
Enter Name:
sanika
Enter Age:
21
1.Insert Record
2.View Address Book
3.Modify Record
4.Delete Record
5.Exit
Enter your choice:
1
Enter Name:
sumit
Enter Age:
23
1.Insert Record
2.View Address Book
3.Modify Record
4.Delete Record
5.Exit
Enter your choice:
1
Enter Name:
sanika
Enter Age:
21
1.Insert Record
2.View Address Book
3.Modify Record
4.Delete Record
5.Exit
Enter your choice:
2
sanika 21
sumit 23
sanika 21
1.Insert Record
2.View Address Book
3.Modify Record
4.Delete Record
5.Exit
Enter your choice:
3
Enter the Old Record:
sanika 21
Enter New Record:
sonal 22
1.Insert Record
2.View Address Book
3.Modify Record
4.Delete Record
5.Exit
Enter your choice:
2
sonal 22
sumit 23
sonal 22
1.Insert Record
2.View Address Book
3.Modify Record
4.Delete Record
5.Exit
Enter your choice:
4
Enter record to delete:
sonal 22
1.Insert Record
2.View Address Book
3.Modify Record
4.Delete Record
5.Exit
Enter your choice:
2
sumit 23
1.Insert Record
2.View Address Book
3.Modify Record
4.Delete Record
5.Exit
Enter your choice:
5
Exit