#!/bin/bash
opt=1
while [ "$opt" -lt 6 ]; do
echo -e "Choose one of the Following\n1. Create a New Address Book\n2. View
Records\n3. Insert new Record\n4. Delete a Record\n5. Modify a Record\n6. Exit"
read opt
case $opt in
1)
echo "Enter filename"
read fileName
if [ -e "$fileName" ]; then
rm "$fileName"
fi
echo -e "NAME\tNUMBER\t\tADDRESS\n===============================\n" >
"$fileName"
cont=1
while [ "$cont" -gt 0 ]; do
echo "Enter Name"
read name
echo "Enter Phone Number of $name"
read number
echo "Enter Address of $name"
read address
echo -e "$name\t$number\t\t$address" >> "$fileName"
echo "Enter 0 to Stop, 1 to Enter next"
read cont
done
;;
2)
cat "$fileName"
;;
3)
echo "Enter Name"
read name
echo "Enter Phone Number of $name"
read number
echo "Enter Address of $name"
read address
echo -e "$name\t$number\t\t$address" >> "$fileName"
;;
4)
echo "Delete record\nEnter Name/Phone Number"
read data
temp="temp"
grep -v "$data" "$fileName" > "$temp"
mv "$temp" "$fileName"
;;
5)
echo "Modify record\nEnter Name/Phone Number"
read data
temp="temp"
grep -v "$data" "$fileName" > "$temp"
mv "$temp" "$fileName"
echo "Enter Name"
read name
echo "Enter Phone Number of $name"
read number
echo "Enter Address of $name"
read address
echo -e "$name\t$number\t$address" >> "$fileName"
;;
esac
done
