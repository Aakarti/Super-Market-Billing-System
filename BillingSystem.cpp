#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<fstream>
#include<string>
#include<stdlib.h>
usingnamespacestd;
classproduct
{
intprno;
charname[50];
floatprice,qty,dis,tax;
public:
voidcreatepr()
{
cout<<endl<<"Entertheproductnumber"<<endl;
cin>>prno;
cout<<"Entertheproductname"<<endl;
std::cin>>name;
cout<<"Enterthepriceoftheproduct"<<endl;
cin>>price;
cout<<"Enterthediscountpercentage"<<endl;
cin>>dis;
}
voidshowpr()
{
cout<<"Productnumber:"<<prno<<endl;
cout<<"Productname:"<<std::cout<<name<<endl;
cout<<"Productprice:"<<price<<endl;
cout<<"Discountpercentage:"<<dis<<endl;
}
intretprno()
{
returnprno;
}
floatretprice()
{
returnprice;
}
char*retname()
{
returnname;
}
intretdis()
{
returndis;
}
};
fstreamfp;
productpr;
intwritepr()
{
fp.open("SMBS.dat",ios::out|ios::app);
pr.createpr();
fp.write((char*)&pr,sizeof(product));
fp.close();
return0;
}
intdisp()
{
cout<<"Displayalltherecords:"<<endl;
fp.open("SMBS.dat",ios::in|ios::out);
while(fp.read((char*)&pr,sizeof(product)))
{
pr.showpr();
}
fp.close();
return0;
}
intdispsp()
{
intflag=0,n;
cout<<"Entertheproductnumber:"<<endl;
cin>>n;
fp.open("SMBS.dat",ios::in|ios::out);
while(fp.read((char*)&pr,sizeof(product)))
{
if(pr.retprno()==n)
{
pr.showpr();
flag=1;
}
}
fp.close();
if(flag==0)
{
cout<<"Recorddoesnotexist"<<endl;
}
return0;
}
intmodifypr()
{
intno,found=0;
system("cls");
cout<<"Entertheproductnumber:"<<endl;
cin>>no;
fp.open("SMBS.dat",ios::in|ios::out);
while(fp.read((char*)&pr,sizeof(product))&&found==0)
{
if(pr.retprno()==no)
{
pr.showpr();
cout<<"Enterthenewdetailsoftheproduct:"<<endl;
pr.createpr();
intlonglongpos=-1*sizeof(pr);
fp.seekp(pos,ios::cur);
fp.write((char*)&pr,sizeof(product));
cout<<"Thedetailsoftheproducthasbeenmodified"<<endl;
found=1;
}
}
fp.close();
if(found==0)
{
cout<<"Recordnotfound"<<endl;
}
return0;
}
intdeletepr()
{
intnum;
system("cls");
cout<<"Entertheproductnumberoftheproductyouwanttodelete"<<endl;
cin>>num;
fp.open("SMBS.dat",ios::in|ios::out);
fstreamfp2;
fp2.open("Temporary.dat",ios::out);
fp.seekg(0,ios::beg);
while(fp.read((char*)&pr,sizeof(product)))
{
if(pr.retprno()!=num)
{
fp2.write((char*)&pr,sizeof(product));
}
}
fp2.close();
fp.close();
remove("SMBS.dat");
rename("Temporary.dat","SMBS.dat");
cout<<"Therecordoftheproducthasbeendeleted"<<endl;
return0;
}
intmenu()
{
system("cls");
fp.open("SMBS.dat",ios::in);
if(!fp)
{
cout<<"Error:Thefilecannotbeopened,headovertotheAdminmenutocreateanew
file."<<endl;
exit(0);
}
else
cout<<"ProductMenu:"<<endl;
cout<<"---------------------------------------------"<<endl;
cout<<"Productnumber:\t\tName:\t\tPrice:"<<endl;
cout<<"---------------------------------------------"<<endl;
while(fp.read((char*)&pr,sizeof(product)))
{
cout<<"\t"<<pr.retprno()<<"\t\t"<<pr.retname()<<"\t\t"<<pr.retprice()<<endl;
}
fp.close();
return0;
}
intplaceorder()
{
system("cls");
intorder[50],quan[50],c=0;
floatamt,damt,total=0;
charch='Y';
menu();
cout<<"\n\n\n\n---------------------------------------------";
cout<<"\n-Placeyourorder-"<<endl;
cout<<"---------------------------------------------"<<endl;
do
{
cout<<"Entertheproductnumber:"<<endl;
cin>>order[c];
cout<<"Enterthequantity:"<<endl;
cin>>quan[c];
c++;
cout<<"Dowanttoorderanotherproduct?(Y/N):"<<endl;
cin>>ch;
}while(ch=='y'||ch=='Y');
cout<<"Invoice:"<<endl;
cout<<"Product number\tProduct Name\tQuantity\tPrice\tAmount\tAmount after
discount"<<endl;
for(intx=0;x<=c;x++)
{
fp.open("SMBS.dat",ios::in);
fp.read((char*)&pr,sizeof(product));
while(!fp.eof())
{
if(pr.retprno()==order[x])
{
amt=pr.retprice()*quan[x];
damt=amt-(amt*pr.retdis()/100);
cout<<"\n"<<"\t"<<order[x]<<"\t"<<pr.retname()<<"\t\t"<<quan[x]<<"\t\t"<<pr.retprice()<<"\t"<<amt<
<"\t\t"<<damt;
total=total+damt;
}
fp.read((char*)&pr,sizeof(product));
}
fp.close();
}
cout<<"\n\n\t\t\t\t\tTotal:"<<total;
return0;
}
intinto()
{
cout<<"-----SuperMarketBillingSystemVersion2-----"<<endl;
cout<<"\nMadeby:code-projects.org"<<endl;
return0;
}
intadmin()
{
system("cls");
charch2;
cout<<"Administrationmenu:"<<endl;
cout<<"1.Createaproduct."<<endl;
//cout<<"2.Displayallproducts."<<endl;
//cout<<"3.Query-Displayaspecificproduct."<<endl;
cout<<"2.Modifyaproduct"<<endl;
cout<<"3.Deleteaproduct."<<endl;
cout<<"4.Viewproductmenu."<<endl;
cout<<"5.Backtomainmenu()."<<endl;
cout<<"Enteryourchoice:"<<endl;
ch2=getche();
switch(ch2)
{
case'1':
{
writepr();
break;
}
//case'2':
{
disp();
break;
}
//case'3':
{
system("cls");
dispsp();
break;
}
case'2':
{
modifypr();
break;
}
case'3':
{
deletepr();
break;
}
case'4':
{
menu();
getch();
}
case'5':
{
break;
}
default:cout<<"\a";admin();
}
return0;
}
intmain()
{
charch;
into();
do
{
cout<<"\n\nWelcometoTheSuperMarketBillingSystemApplication"<<endl;
cout<<"MainMenu:"<<endl;
cout<<"1.Customer"<<endl;
cout<<"2.Administrator"<<endl;
cout<<"3.Exit"<<endl;
cout<<"Enteryourchoice:"<<endl;
ch=getche();
switch(ch)
{
case'1':
{
placeorder();
getch();
break;
}
case'2':
{
admin();
break;
}
case'3':
{
exit(0);
}
default:cout<<"\a";
}
system("cls");
}while(ch!=3);
return0;
}
