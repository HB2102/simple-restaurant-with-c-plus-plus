#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cmath>
#include<iomanip>
#include<cstdlib>
#include <stdio.h>






using namespace std;







struct food
{
	
	
	string name;
	string price;
	string preparetime;
	string description;
	
	
};











main()
{
	
	
	system("color 03");
	cout<<"SALAM !!!"<<endl<<"Be restourane ma khosh amadid."<<endl<<endl;
	int r=1;
	int vaziat=0,pk=0;
	
	
	while((r==1)or(r==2)){
		                   cout<<endl<<"===================================================================================================================================="<<endl;
				           cout<<"1. Vorood Be Onvane Moshtari"<<endl<<"2. Vorood Be Onvane Modiriat"<<endl<<"3. Khorooj"<<endl<<endl;
	                       cin>>r;
	                       if( r==1 ){
		                              int code;
	                                  cout<<"che no ghazei mikhaahid? Shomareye menoye an ra vared konid:"<<endl;
	                                  cout<<endl<<"1.Ghazaye KHanegi"<<endl<<"2.Fast Food"<<endl<<endl;
	                                  cin>>code;
                                      cout<<"================================================================================================================================"<<endl;





	                                  if(code==1){
		                                          cout<<"Menoye Ghazaye Khanegi"<<endl;
		                                          int q=0;
	                                              ifstream menu("chmenu.txt");
	                                              string khat;
	                                              food ghaza[22];
	
	                                              int i=0;
	                                              while(getline(menu,khat)){
		                                                                    stringstream harkhat(khat);
		                                                                    getline(harkhat,ghaza[i].name,',');
		                                                                    getline(harkhat,ghaza[i].price,',');
		                                                                    getline(harkhat,ghaza[i].preparetime,',');
		                                                                    getline(harkhat,ghaza[i].description,',');
		                                                                    i++;
	                                                                       }
	                         
	                         
	                         
	                         
	                         
	                         
	                         
	                                              cout<<"================================================================================================================================"<<endl;
	                                              cout<<"   Name Ghaza"<<'\t'<<'\t'<<'\t'<<"Gheymat(Tooman)"<<'\t'<<'\t'<<"Zamane Amade Sazi(daghighe)"<<'\t'<<'\t'<<"Tozihat"<<endl;
	
	
	

	
	
	                                              for(int j=1;j<=22;j++){
		                                                                 int a=ghaza[j-1].name.length();
		                                                                 if((j<10)&(a<13))cout<<j<<". "<<ghaza[j-1].name<<'\t'<<'\t'<<'\t'<<ghaza[j-1].price<<'\t'<<'\t'<<'\t'<<ghaza[j-1].preparetime<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<ghaza[j-1].description<<endl;
		                                                                 if((j<10)&(a>12)&(a<19))cout<<j<<". "<<ghaza[j-1].name<<'\t'<<'\t'<<ghaza[j-1].price<<'\t'<<'\t'<<'\t'<<ghaza[j-1].preparetime<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<ghaza[j-1].description<<endl;
		                                                                 if((j<10)&(a>18)&(a<20))cout<<j<<". "<<ghaza[j-1].name<<'\t'<<'\t'<<ghaza[j-1].price<<'\t'<<'\t'<<'\t'<<ghaza[j-1].preparetime<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<ghaza[j-1].description<<endl;
		                                                                 if((j<10)&(a>19))cout<<j<<". "<<ghaza[j-1].name<<'\t'<<ghaza[j-1].price<<'\t'<<'\t'<<'\t'<<ghaza[j-1].preparetime<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<ghaza[j-1].description<<endl;
		                                                                 if((j>9)&(a<13))cout<<j<<"."<<ghaza[j-1].name<<'\t'<<'\t'<<'\t'<<ghaza[j-1].price<<'\t'<<'\t'<<'\t'<<ghaza[j-1].preparetime<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<ghaza[j-1].description<<endl;
		                                                                 if((j>9)&(a>12)&(a<19))cout<<j<<"."<<ghaza[j-1].name<<'\t'<<'\t'<<ghaza[j-1].price<<'\t'<<'\t'<<'\t'<<ghaza[j-1].preparetime<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<ghaza[j-1].description<<endl;
		                                                                 if((j>9)&(a>18))cout<<j<<"."<<ghaza[j-1].name<<'\t'<<ghaza[j-1].price<<'\t'<<'\t'<<'\t'<<ghaza[j-1].preparetime<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<ghaza[j-1].description<<endl;
		                   
	                                                                    }
	
	
	
	
	
	
	
	                                              int time[22],pool[22];
	                                              for(int k=0;k<=21;k++){
		                                                                 time[k]=stoi(ghaza[k].preparetime);
		                                                                 pool[k]=stoi(ghaza[k].price);
	                                                                    }
	
	
	
	
	
	
	                                              cout<<"===================================================================================================================================="<<endl;
	                                              cout<<"Baraye entekhab ghaza shomare meno an ra vared konid"<<endl;
	                                              cout<<"Dar soorat etmam sefaresh adad 0 ra vared konid!"<<endl<<endl;
	                                              string name[100];
	                                              int tedad[100],gheymat[100];
	                                              int s=0,max=0,e=-1,p;
	                                              while(e!=0){
		                                                      cin>>e;
		                                                      if(e==0)break;
		                                                      if(e>22){
		         	                                                   cout<<"adad shma dar meno vojoud nadarad"<<endl<<endl;
		         	                                                   continue;
				                                                      }
				                                              name[q]=ghaza[e-1].name;
		                                                      cout<<"che tedad az "<<ghaza[e-1].name<<" mikhahid?"<<endl;
				                                              cin>>p;
				                                              if(p<1){
				                                   	                  cout<<"ERROR!!! adad vared shde motabar nist az aval shomare meno ra vared konid"<<endl<<endl;
				                                   	                  continue;
												                     }
				                                              tedad[q]=p;
				                                              gheymat[q]=p*pool[e-1];
				                                              q++;
				                                              cout<<"Agar sefaresh digari darid adad an ra vared konid dar gheyre in soorat 0 ra vared konid"<<endl<<endl;
				                                              s+=p*pool[e-1];
				                                              if(time[e-1]>max)max=time[e-1]; 
	                                                         }
	
	
	
	
	
	
	                                              cout<<"===================================================================================================================================="<<endl;     
	                                   
	                                   
	                                   
	                                   
	                                   
									   
									   
									              int t;
	                                              cout<<"factor shoma "<<endl<<endl;
	                                              cout<<"   Name sefaresh"<<'\t'<<'\t'<<"tedad"<<'\t'<<'\t'<<"Gheymat"<<endl;
	                                              for(int j=0;j<=q-1;j++){
		                                                                  t=name[j].length();        
		                                                                  if((j<10)&(t<13))cout<<j+1<<" ."<<name[j]<<'\t'<<'\t'<<'\t'<<tedad[j]<<'\t'<<'\t'<<gheymat[j]<<endl;
		                                                                  if((j<10)&(t>12)&(t<19))cout<<j+1<<" ."<<name[j]<<'\t'<<'\t'<<tedad[j]<<'\t'<<'\t'<<gheymat[j]<<endl;
		                                                                  if((j<10)&(t>18)&(t<20))cout<<j+1<<" ."<<name[j]<<'\t'<<'\t'<<tedad[j]<<'\t'<<'\t'<<gheymat[j]<<endl;
		                                                                  if((j<10)&(t>19))cout<<j+1<<" ."<<name[j]<<'\t'<<tedad[j]<<'\t'<<'\t'<<gheymat[j]<<endl;
		                                                                  if((j>9)&(t<13))cout<<j+1<<"."<<name[j]<<'\t'<<'\t'<<'\t'<<tedad[j]<<'\t'<<'\t'<<gheymat[j]<<endl;
		                                                                  if((j>9)&(t>12)&(t<19))cout<<j+1<<"."<<name[j]<<'\t'<<'\t'<<tedad[j]<<'\t'<<'\t'<<gheymat[j]<<endl;
		                                                                  if((j>9)&(t>18))cout<<j+1<<"."<<name[j]<<'\t'<<tedad[j]<<'\t'<<'\t'<<gheymat[j]<<endl;
		                                                                  i++;
	                                                                     }
	
	
	
	                                              cout<<endl<<" Jame sefaresh shoma ==>> "<<s<<" T"<<endl<<endl;
	                                   
	                                              cout<<"agar mikhahid sefarehs ra pardakht konid adad-e 1 ra vared konid dar gheyre in soorat adad-e digari ra vared konid: "<<endl;
	                                              int pardakht;
	                                              cin>>pardakht;
	                                              if(pardakht==1){
	                                   	                          pk=1;
	                                   	                          ofstream order("order.txt",ios::app);
	                                                              for(int i=0;i<=q-1;i++){
	                                   	                                                  order<<name[i]<<" ,";
	                                   	                                                  order<<tedad[i]<<endl;
									                                                     }
	                                   	                          cout<<" sefaresh shoma sabt shod va ta "<<max<<" daghigeye digar hazer mishavad.";
	                                                              cout<<endl<<endl<<" ba tashakor az sefaresh shoma"<<endl<<" Rooz Khosh"<<endl;
									                             }
									              else cout<<"sefaresh shoma cancle shod. agar sefarsh digari darid az aval marahel ra tey konid.";
	                                             }
	                       
	                       
	                       
	                       
	                       
	                       
	                       
	                       
	                       
	                       
	                       if(code==2){
		                               cout<<"Menoye Fast Food"<<endl;
		                               int q=0;
	                                   ifstream menu("cfmenu.txt");
	                                   string khat;
	                                   food ghaza[22];
	
	                                   int i=0;
	                                   while(getline(menu,khat)){
		                                                         stringstream harkhat(khat);
		                                                         getline(harkhat,ghaza[i].name,',');
		                                                         getline(harkhat,ghaza[i].price,',');
		                                                         getline(harkhat,ghaza[i].preparetime,',');
		                                                         getline(harkhat,ghaza[i].description,',');
		                                                         i++;
	                                                            }
	                         
	                         
	                         
	                         
	                         
	                         
	                                   cout<<"================================================================================================================================"<<endl;
	                                   cout<<"   Name Ghaza"<<'\t'<<'\t'<<'\t'<<"Gheymat(Tooman)"<<'\t'<<'\t'<<"Zamane Amade Sazi(daghighe)"<<'\t'<<'\t'<<"Tozihat"<<endl;
	
	
	                                   for(int j=1;j<=22;j++){
		                                                      int a=ghaza[j-1].name.length();
		                                                      if((j<10)&(a<13))cout<<j<<". "<<ghaza[j-1].name<<'\t'<<'\t'<<'\t'<<ghaza[j-1].price<<'\t'<<'\t'<<'\t'<<ghaza[j-1].preparetime<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<ghaza[j-1].description<<endl;
		                                                      if((j<10)&(a>12)&(a<19))cout<<j<<". "<<ghaza[j-1].name<<'\t'<<'\t'<<ghaza[j-1].price<<'\t'<<'\t'<<'\t'<<ghaza[j-1].preparetime<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<ghaza[j-1].description<<endl;
		                                                      if((j<10)&(a>18)&(a<20))cout<<j<<". "<<ghaza[j-1].name<<'\t'<<'\t'<<ghaza[j-1].price<<'\t'<<'\t'<<'\t'<<ghaza[j-1].preparetime<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<ghaza[j-1].description<<endl;
		                                                      if((j<10)&(a>19))cout<<j<<". "<<ghaza[j-1].name<<'\t'<<ghaza[j-1].price<<'\t'<<'\t'<<'\t'<<ghaza[j-1].preparetime<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<ghaza[j-1].description<<endl;
		                                                      if((j>9)&(a<13))cout<<j<<"."<<ghaza[j-1].name<<'\t'<<'\t'<<'\t'<<ghaza[j-1].price<<'\t'<<'\t'<<'\t'<<ghaza[j-1].preparetime<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<ghaza[j-1].description<<endl;
		                                                      if((j>9)&(a>12)&(a<19))cout<<j<<"."<<ghaza[j-1].name<<'\t'<<'\t'<<ghaza[j-1].price<<'\t'<<'\t'<<'\t'<<ghaza[j-1].preparetime<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<ghaza[j-1].description<<endl;
		                                                      if((j>9)&(a>18))cout<<j<<"."<<ghaza[j-1].name<<'\t'<<ghaza[j-1].price<<'\t'<<'\t'<<'\t'<<ghaza[j-1].preparetime<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<ghaza[j-1].description<<endl;
		                   
	                                                         }
	
	                                   int time[22],pool[22];
	                                   for(int k=0;k<=21;k++){
		                                                      time[k]=stoi(ghaza[k].preparetime);
		                                                      pool[k]=stoi(ghaza[k].price);
	                                                         }
	
	
	
	
	
	
	
	                                   cout<<"===================================================================================================================================="<<endl;
	                                   cout<<"Baraye entekhab ghaza shomare meno an ra vared konid"<<endl;
	                                   cout<<"Dar soorat etmam sefaresh adad 0 ra vared konid!"<<endl<<endl;
	                                   string name[100];
	                                   int tedad[100],gheymat[100];
	                                   int s=0,max=0,e=-1,p;
	                                   while(e!=0){
		                                           cin>>e;
		                                           if(e==0)break;
		                                           if(e>22){
		         	                                        cout<<"adad shma dar meno vojoud nadarad"<<endl<<endl;
		         	                                        continue;
				                                           }
				                                   name[q]=ghaza[e-1].name;
		                                           cout<<"che tedad az "<<ghaza[e-1].name<<" mikhahid?"<<endl;
				                                   cin>>p;
				                                   if(p<1){
				                                   	       cout<<"ERROR!!! adad vared shde motabar nist az aval shomare meno ra vared konid"<<endl<<endl;
				                                   	       continue;
												          }
				                                   tedad[q]=p;
				                                   gheymat[q]=p*pool[e-1];
				                                   q++;
				                                   cout<<"Agar sefaresh digari darid adad an ra vared konid dar gheyre in soorat 0 ra vared konid"<<endl<<endl;
				                                   s+=p*pool[e-1];
				                                   if(time[e-1]>max)max=time[e-1]; 
	                                              }
	
	
	
	

	                                   cout<<"===================================================================================================================================="<<endl;     
	                                   
									   
									   
									   
									   int t;
	                                   cout<<"factor shoma "<<endl<<endl;
	                                   cout<<"   Name sefaresh"<<'\t'<<'\t'<<"tedad"<<'\t'<<'\t'<<"Gheymat"<<endl;
	                                   for(int j=0;j<=q-1;j++){
		                                                       t=name[j].length();        
		                                                       if((j<10)&(t<13))cout<<j+1<<" ."<<name[j]<<'\t'<<'\t'<<'\t'<<tedad[j]<<'\t'<<'\t'<<gheymat[j]<<endl;
		                                                       if((j<10)&(t>12)&(t<19))cout<<j+1<<" ."<<name[j]<<'\t'<<'\t'<<tedad[j]<<'\t'<<'\t'<<gheymat[j]<<endl;
		                                                       if((j<10)&(t>18)&(t<20))cout<<j+1<<" ."<<name[j]<<'\t'<<'\t'<<tedad[j]<<'\t'<<'\t'<<gheymat[j]<<endl;
		                                                       if((j<10)&(t>19))cout<<j+1<<" ."<<name[j]<<'\t'<<tedad[j]<<'\t'<<'\t'<<gheymat[j]<<endl;
		                                                       if((j>9)&(t<13))cout<<j+1<<"."<<name[j]<<'\t'<<'\t'<<'\t'<<tedad[j]<<'\t'<<'\t'<<gheymat[j]<<endl;
		                                                       if((j>9)&(t>12)&(t<19))cout<<j+1<<"."<<name[j]<<'\t'<<'\t'<<tedad[j]<<'\t'<<'\t'<<gheymat[j]<<endl;
		                                                       if((j>9)&(t>18))cout<<j+1<<"."<<name[j]<<'\t'<<tedad[j]<<'\t'<<'\t'<<gheymat[j]<<endl;
		                                                       i++;
	                                                          }
	
	
	
	                                   cout<<endl<<" Jame sefaresh shoma ==>> "<<s<<" T"<<endl<<endl;
	                                   
	                                   cout<<"agar mikhahid sefarehs ra pardakht konid adad-e 1 ra vared konid dar gheyre in soorat adad-e digari ra vared konid: "<<endl;
	                                   int pardakht;
	                                   cin>>pardakht;
	                                   if(pardakht==1){
	                                   	               pk=1;
	                                   	               ofstream order("order.txt",ios::app);
	                                                   for(int i=0;i<=q-1;i++){
	                                   	                                       order<<name[i]<<" ,";
	                                   	                                       order<<tedad[i]<<endl;
									                                          }
	                                   	               cout<<" sefaresh shoma sabt shod va ta "<<max<<" daghigeye digar hazer mishavad.";
	                                                   cout<<endl<<endl<<" ba tashakor az sefaresh shoma"<<endl<<" Rooz Khosh"<<endl;
									                  }
									   else cout<<"sefaresh shoma cancle shod. agar sefarsh digari darid az aval marahel ra tey konid.";
	                                   
	                                  }
	                       
						   
						   
						   
						   
						   
						   if((code!=1)&(code!=2)){
	                       	                       cout<<"ERROR!! Adad Vared Shode Sahih Nemibashad.";
						                          }
	                       }
	            
	           
			   
			    
			    
			    
	            
	            
	            
	            
	                       if( r==2 ){
	            	                  string p="0",u="0";
	            	                  while((p!="1234")or(u!="manager")){
	            	       	                                             cout<<endl<<endl<<"Name karbari khod ra vared konid: ";
	            	                                                     cin>>u;
	            	                                                     cout<<endl<<"Ramze vorood ra vared konid: ";
	            	                                                     cin>>p;
	            	                                                     if((p=="1234")&(u=="manager")){
	            	                                                     	                             cout<<"vorood ba movafaghiat anjam shod";
	            	                                                     	                             break;
															                                           }
	            	                                                     else cout<<"nam-e karbari ya ramze oboor eshtabah ast az aval talash konid.";
						                                                }
						   
						   
						   
						   
						   
						   
	            	                  cout<<endl<<"===================================================================================================================================="<<endl;
	            	                  if(pk==0)cout<<"sefareshi daryaft nashode mitavanid kharej shavid.";
	            	                  if(pk==1){
	            	                  	         cout<<"sefareshe daryaft shode.";
	            	       	                    ifstream order("order.txt");
	            	       	                    string sefaresh;
	            	       	                    string naam[100],num[100];
	            	       	                    int i=0;
	            	       	                    while(getline(order,sefaresh)){
									           	                            stringstream ghaza(sefaresh);	
		                                                                       getline(ghaza,naam[i],',');
		                                                                       getline(ghaza,num[i],',');
		                                                                       i++;
	                                                                          }
	                                           
								                cout<<"   Name sefaresh"<<'\t'<<'\t'<<"tedad"<<endl; 			                       
	                                            for(int j=0;j<=i;j++){
	                                            	                   int t;
	                                            	                   t=naam[i].length();
	                                 	                              if((j<10)&(t<13))cout<<j+1<<" ."<<naam[j]<<'\t'<<'\t'<<'\t'<<num[j]<<endl;
		                                                              if((j<10)&(t>12)&(t<19))cout<<j+1<<" ."<<naam[j]<<'\t'<<'\t'<<num[j]<<endl;
		                                                              if((j<10)&(t>18)&(t<20))cout<<j+1<<" ."<<naam[j]<<'\t'<<'\t'<<num[j]<<endl;
		                                                              if((j<10)&(t>19))cout<<j+1<<" ."<<naam[j]<<'\t'<<num[j]<<endl;
		                                                              if((j>9)&(t<13))cout<<j+1<<"."<<naam[j]<<'\t'<<'\t'<<'\t'<<num[j]<<endl;
		                                                              if((j>9)&(t>12)&(t<19))cout<<j+1<<"."<<naam[j]<<'\t'<<'\t'<<num[j]<<endl;
		                                                              if((j>9)&(t>18))cout<<j+1<<"."<<naam[j]<<'\t'<<num[j]<<endl;
		                                                   
									                                 }
								           	 
												
												
												
												int n;
								           	 cout<<"dar soorat amade shodan sefaresh adad 1 ra vared konid dar gheyre in soorat adad digari ra vared konid:";
								           	 cin>>n;
								           	 if(n==1)cout<<"sefaresh amade shod";
								           	 else cout<<"sefaresh hanooz amade nashode";
						                       }
	    
				                     }
	            
	            
	            
	            
	            
	            
	            
	            
	            
	            
	            
	            
	            
	                       if( r==3 ){
			           	           cout<<"Mamnoon az hosne entekhaab e shoma";
				           		   break;
				                     }
	            
	            
	           }
	
}