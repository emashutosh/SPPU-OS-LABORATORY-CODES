ch=0
echo enter the file name:
read fname
touch $fname
while [ $ch -lt 20 ] ; do
echo 1.create
echo 2.display
echo 3.insert
echo 4.delete
echo 5.modify
echo 6.search
echo 7.exit

echo enter your choice:
read ch
case $ch in

1)
echo enter the name:
read name
echo enter the pincode:
read pin
echo enter the housenumber:
read hno
echo $name $pin $hno >>$fname
echo file created
;;
2)
cat $fname
;;
3)
echo enter the name:
read name
echo enter the pincode:
read pin
echo enter the housenumber:
read hno
echo $name $pin $hno >>$fname
echo file inserted
;;
4)
echo enter the name to be deleted:
read name
if grep -w "^$name" $fname
then
grep -wv "^$name" $fname >> temp
rm $fname
mv temp $fname
echo record deleted.
else 
echo record not found.
fi
;;

5)
echo enter the name to be modified:
read name
if grep -w "^$name" $fname
then
grep -wv "^$name" $fname >>temp
rm $fname
mv temp $fname
echo enter the name:
read name1
echo enter the pincode:
read pin1
echo enter the housenumber:
read hno1
echo $name1 $pin1 $hno1 >>$fname
echo file modified.
fi
;;

6)
echo enter the name to be searched:
read name
if grep -w "$name" $fname
then 
grep -w "$name" $fname |echo
echo record found
else 
echo record not found
fi
;;

7)
echo exit
;;

*)
echo you have inserted wrong choice
;;
esac
done
