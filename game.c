//2048 oyunun c dilinde kodlanmasý

#include <stdio.h>
#include <time.h>

int main(){
	srand(time(NULL));
	
	int i, j, a[100][100], k, l, sonuc = 0, score = 0, kontrol, n, t, sayac, b, counter, x, Satir[100], Sutun[100], R[100][100], scoreR, counter1 = 1, kontrol1, y, maxscore = 0, kontrol2;
	char eylem, Eylem[] = "WASDERX";
	
	for ( i = 1; i <= 8; i++ ){ //Baþlangýçta matrisin bütün elemanlarýna 0 deðerinin atanmasý
		
		for ( j = 1; j <= 8; j++ ){
			
			a[i][j] = 0;
		} 
	}
	
	//4x4 boyundaki a[i][j] matrisinin rastgele iki elemanýna 2 veya 4 deðerinin atanmasý
	//Matrisin rastgele bir elemanýna 2 veya 4 deðerinin atanmasý
	i = rand()%4 + 1;//Rastgele bir satýr seçilmesi
	j = rand()%4 + 1;//Rasgele bir sütun seçilmesi
	
	a[i][j] = (rand()%2 + 1) * 2;//Seçilen satýr ve sütunun olduðu yere 2 veya 4 deðerinin rastgele atanmasý
	
	//2 veya 4 deðerinin atandýðý ilk yere 2 veya 4 deðerinin yeniden atanmamasý için do...while döngüsünün kullanýlmasý
	do{
		
	k = rand()%4 + 1;
	l = rand()%4 + 1;
	
	a[k][l] = (rand()%2 + 1) * 2;
		
	}while ( k == i && l == j );//Seçilen satýr ve sütun ilk rastgle deðerin atandýðý satýr ve sütuna eþit olduðu sürece döngüye devam et 
	
	do{
		
		if( counter1 != 0 ){
			
			sonuc = 0;//Matriste 2048 deðerinin olup olmadýðýnýn kontrolü için kullanýlan deðiþken
			//Matristeki sayýlarýn kutucuklar içinde ekranda yazdýrýlmasý
			//Kutucuklarýn alt alta iki tane | karakterinin ve - karekterinin yan yana yazdýrýlmasýyla oluþmasý
			//Tek bir kutucuk için bir tane karekteri yazdýrýldýðýnda matristeki sayýyla beraber - karekteri yazdýrýldýðýnda kutucuklarýn görüntüsü bozulduðu için iki tane alt alt | karekterinin yazdýrýlmasý
			//Matristeki sayýlarýn yazdýrýlmasý için 8 satýr ve 4 sütun þeklindeki kutucuklarýn yazdýrýlmasý
			printf( "____________________\n" );
		
			for ( i = 1; i <= 8; i++ ){
		
				for( j = 1; j <= 4; j++ ){
			
					if ( i % 2 == 0 ){//Satýr numarasý çift ise kutucuðun içinin boþ olarak gösterilmesi
					
						printf( "|____" );
					}
					else{//Satýr numarasý tek ise a[4][4] matrisindeki sayýlarýn kutucuklar içinde gösterilemsi
					
						if ( a[i/2+1][j] == 0 ){//Matristeki eleman 0 ise kutucuðun içini boþ olarak göster
					
							printf( "|    " );
						}
					
						else{
						
							if ( a[i/2+1][j] == 2048 ){//Matristeki eleman 2048 ise sonuc deðiþkenine 1 deðerini ata
							
								sonuc = 1;
							}
							
							sayac = 1;//Çýktýda gösterilecek olan sayýnýn saðýnda ne kadar boþluk olacaðýnýn hesaplanmasýna yarayan deðiþken
							b = 10;//Matristeki sayýnýn kaç basamaklý olduðunu yani çýktýda ne kadar yer kaplayacaðýný hesaplamak için kullanýlan deðiþken
						
							//Rastgele atanan 2 veya 4 deðerinin çýktada * karekteri ile birlikte gösterilmesi
							if ( i/2+1 == Satir[x] && j == Sutun[x] ){//Eðer i/2+1 ve j deðerleri rastgele atanan 2 veya 4 deðerinin bulunduðu satýr ve sütuna eþit ise bu deðeri * karekteri ile birlikte göster
							
								printf( "|%d*  ", a[i/2+1][j] );
							}
						
							else{//Eðer rastgele atanan sayý deðilse
							
								while ( a[i/2+1][j] / b != 0 ){//Matristeki sayýnýn basamak sayýsýnýn hesaplanmasý
							
									b = b * 10;
									++sayac;
								}
							
								printf( "|%d", a[i/2+1][j] );
						
								for ( k = 1; k <= 4 - sayac; k++ ){//Matristeki sayýnýn basamak sayýsýna yani ekranda ne kadar yer kapladýðýna baðlý olarak saðýndaki boþluklarýn yazdýrýlmasý
							
									printf(" ");
								}
							}
						}
					}
				}
		
				printf( "|\n" );//Matristeki ilgili satýrdaki bütün sayýlar yazdýrýldýktan sonra alt satýra geç
			}
			
			if (kontrol2 == 1 ){
				
				printf( "Highest Score: %d\n", maxscore );//En yüksek skorun yazdýrýlmasý
			}
			
		}		
		
		//a[i][j] matrisindeki bütün elemanlarýn sýfýrdan farklý olup olmadýðýnýn ve W,A,S,D tuþlarýndan herhangi birine basýldýðýnda matrisin deðiþip deðiþmediðinin kontrol edilmesi
		counter = 0;//W,A,S,D tuþlarýndan herhangi birine basýldýðýnda matrisin bütün yerlerinin dolup dolmadýðýný ve elemanlarýn yerlerinin deðiþip deðiþmediðini kontrol eden deðiþken
		for ( i = 1; i <= 4; i++ ){
			
			for ( j = 1; j <= 4; j++ ){
				
				//a[i][j] matrisindeki ardýþýk elemanlarýn birbirine eþit olup olmadýðýna bakýlmasý
				if ( a[i][j] == a[i][j+1] || a[i][j] == a[i+1][j] ){//Matristeki ardýþýk elemanlarýn eþit olmasý halinde matristeki elemanlar hareket edebilecektir yani oyun hala devam edecektir
					
					++counter;
				}
				
				if ( a[i][j] == 0 ){//a[i][j] deðerinin 0 olup olmadýðýnýn kontrolü
					
					++counter;
				}
			}
		}
		
		if ( counter != 0 || sonuc != 1){
			
			kontrol1 = 0; 
			do{//W,A,S,D,E,R,X dýþýndaki tuþlara basýldýðýnda herhangi bir iþlemÝn yapýlmasýnýn engellenmesi
		
				eylem = getch();
				
				y = 0;
				while ( Eylem[y] != '\0' ){
					
					if ( eylem == Eylem[y] ){
						
						kontrol1 = 1;
					}
					++y;
				}
				
			}while( kontrol1 == 0 );
	
						
			if ( eylem == 'R' ){//R tuþuna basýldýðýnda önceki aþamaya dönülmesi
					
				score = scoreR;//scoreR deðiþkeninde saklanan önceki aþamanýn skorunun score deðiþkenine atanmasý
				for ( i = 1; i <= 4; i++ ){//Önceki aþamadaki a[i][j] matrisindeki deðerlerin saklandýðý R[i][j] matrisindeki elemanlarýn a[i][j] matrisine atanmasý
						
					for ( j = 1; j <= 4; j++ ){
									
						a[i][j] = R[i][j];
					}
				}
			}
				
			else if ( eylem == 'X' ){// X tuþuna basýlýrsa a[i][j] matrisinin sýfýrlanmasý ve rastgele 2 elemanýna 2 veya 4 deðerinin rastgele seçilerek deðerinin atanmasý
						
				score = 0;//skorun sýfýrlanmasý
				for ( i = 1; i <= 8; i++ ){//a[i][j] matrisindeki elemanlara 0 deðerinin atanmasý
			
					for ( j = 1; j <= 8; j++ ){
						
						a[i][j] = 0;
					} 
				}
				//Rastgele satýr ve sütun numarasýnýn seçilip i ve j deðiþkenlerine atanmasý
				i = rand()%4 + 1;
				j = rand()%4 + 1;
				
				a[i][j] = (rand()%2 + 1) * 2;//Seçilen i. satýr ve j. sütunda bulunan yere rastgele 2 veya 4 deðerinin atanmasý
				//2 veya 4 deðerinin atandýðý ilk yere 2 veya 4 deðerinin yeniden atanmamasý için do...while döngüsünün kullanýlmasý
				do{
					
					k = rand()%4 + 1;
					l = rand()%4 + 1;
				
					a[k][l] = (rand()%2 + 1) * 2;
					
				}while ( k == i && l == j );//Seçilen satýr ve sütun rastgle deðerin atandýðý satýr ve sütuna eþit olduðu sürece döngüye devam et 
			}
				
			else if ( eylem == 'E' ){//E tuþuna basýlýrsa döngüden çýkmak ve programýn sonlanmasý için sonuc deðiþkenine bir atanmasý
								
				sonuc = 1;
			}
				
			else if ( eylem == 'A' || ( eylem == 'W' || ( eylem == 'D' || eylem == 'S' ) ) ){
				
				for ( i = 1; i <= 4; i++ ){
					
					for ( j = 1; j <= 4; j++ ){
							
						R[i][j] = a[i][j];//Önceki aþamadaký matris elemanlarýn kaybolmamasý için R[i][j] matrisine atanmasý
						scoreR = score;//Önceki aþamadaki skorun deðerinin kaybolmamasý için scoreR deðiþkenine atanmasý
						//W,A,S,D tuþlarýna basýldýðýnda matrisin elemanlarýnýn belirtilen yönde yerlerinin deðiþmesi için her bir tuþ için ayrý bir kod yazmak yerine sadece A tuþuna basýldýðýna yapýlacak iþleme göre diðer tuþlar için matristeki elemanlarýn yerlerinin deðiþtirilmesi
						//Matrisin W tuþu için 90 derece, D tuþu için 180 derece, S tuþu için 270 derece saatin tersi yönüde döndürülmesi
						//Matristeki elemanlarýn yerleri deðiþtirldiðinde atanan yerde bulunan elemanýn kaybolmamasý için elemanlarýn 1. ve 4. satýrlar ile 1. ve 4. sütunlar arasýnda bulunan matrise deðil 1. ve 4. satýrlar ile 1. ve 4. sütunlar arasýnda bulunan matrise atanmasý
						if ( eylem == 'A' ){
						
							a[i+4][j+4] = a[i][j];
						}
									
						else if ( eylem == 'W' ){//a[i][j]'nin saatin tersi yönünde 90 derece döndülerek 4 adým saða 4 adým aþaðý kaydýrýlmasý
							
							a[9-j][i+4] = a[i][j];
						}
								
						else if ( eylem == 'D' ){//a[i][j]'nin saatin tersi yönünde 180 derece döndülerek 4 adým saða 4 adým aþaðý kaydýrýlmasý
							
							a[9-i][9-j] = a[i][j];
						}
						
						else if ( eylem == 'S' ){//a[i][j]'nin saatin tersi yönünde 270 derece döndülerek 4 adým saða 4 adým aþaðý kaydýrýlmasý
				
							a[j+4][9-i] = a[i][j];
						}
					}
				}
								
				//a[i][j] matrisinin her bir elemanýn bulunduðu satýrda solundaki elemanlar 0 olduðu sürece sola kaydýrýlmasý ve solundaki eleman kendisine eþitse toplamýnýn soldaki yere atanmasý
				counter1 = 0;//W,A,S,D tuþlarýndan herhangi birine basýldýðýnda matrisin elemanlarýnýn yerleri deðiþmiyorsa ayný aþamanýn ekrana bir daha yazdýrýlmamasý için kullanýlan deðiþken
				for ( i = 5; i <= 8; i++ ){
				
					t = 4;//Her bir satýrdaki yan yana eþit olan elemanlarýn toplamýyla elde edilen sonucun o satýrdaki sonuca eþit olan baþka bir sayýyla toplanmasýný engellemek için kullanýlan deðiþken
						
					for ( j = 5; j <= 8; j++ ){
						
						if ( a[i][j] != 0 ){//Matristeki 0 olan elemanlarýn karþýlaþtýrýlmasýna gerek olmadýðý için sadece 0'dan farklý olan elemanlara bakýlmasý
						
							k = j;//a[i][j] elemanýnýn solundaki elemanlarla karþýlaþtýrýlmasý için kullanýnlan deðiþken
								
							while ( k > t + 1 ){//Karþýlaþtýrýlacak olan a[i][j] elemanýnýn o satýrdaki toplanmýþ olan deðerle tekrardan toplanmasýnýn önlenmesi
									
								if ( a[i][k] == a[i][k-1] ){//a[i][k] ile a[i][[k-1] eþitse toplamlarýný a[i][k-1]'e ata
										
									a[i][k-1] = a[i][k-1] + a[i][k];
									a[i][k] = 0;
									score = score + a[i][k-1];//Skorun hesaplanmasý
									--k;
									t = k;//Toplanan deðerin atandýðý sütun numarasýnýn t deðiþkeninde saklanmasý
									++counter1;
								}
								
								else if ( a[i][k-1] == 0 ){//a[i][k] deðerinin solundaki eleman 0 ise sola kaydýr
										
									//a[i][k] ile a[i][k-1]'in deðerlerinin yerlerinin deðiþtirlmesi
									a[i][k-1] = a[i][k];
	 								a[i][k] = 0;
									--k;
									++counter1;
								}
										
								else{//Deðilse sonraki elemana geç
							
									--k;
								}
							}
						}
					}
				}
				
				kontrol2 = 0;
				if ( score > maxscore ){//Daha yüksek bir skora ulaþýldýðýnda skorun maxscore deðiþkeninde saklanmasý
					
					maxscore = score;
					kontrol2 = 1;
				}
				
				//Elemanlarýn yerlerinin deðiþtirilmesi için yapýlan iþlemin tersi yapýlarak sayýlar 1. ve 4. satýrlar ile 1. ve 4. sütunlar arasýnda bulunan matrise atanarak yerlerinin düzeltilmesi
				for ( i = 5; i <= 8; i++ ){
						
					for ( j = 5; j <= 8; j++ ){
						
						if ( eylem == 'A' ){
						
							a[i-4][j-4] = a[i][j];
						}
								
						else if ( eylem == 'W' ){
					
							a[j-4][9-i] = a[i][j];
							}
								
						else if ( eylem == 'D' ){
						
							a[9-i][9-j] = a[i][j];
						}
									
						else if ( eylem == 'S' ){
					
							a[9-j][i-4] = a[i][j];
						}
					}	
				}
						
				if ( counter1 != 0 ){
						
					//a[i][j] matrisindeki deðeri 0 olan rastele bir elemana 2 veya 4 deðerinin rastgele atanmasý
					k = 0;
					for ( i = 1; i <= 4; i++ ){
						
						for ( j = 1; j <= 4; j++ ){
							
							if ( a[i][j] == 0 ){
							
								Satir[k] = i;//a[i][j] matrisinde deðeri 0 olan elemanýn satýr numarasýnýn Satir[k] dizine atanmasý
								Sutun[k] = j;//Deðeri 0 olan elemanýn sütun numarasýnýn Sutun[k] dizine atanmasý
								++k;
							}
						}
					}		
						
					x = rand()%k;//a[i][j] matrisindeki 0 olan elemalarýn satýr ve sütun numaralarýný saklayan Satir[k] ve Sutun[k] dizilerindeki elemanlarýn sýra numarasýný gösteren 0 ile k-1 arasýndaki deðerlerden rastgele birinin x deðiþkenine atanmasý
					a[Satir[x]][Sutun[x]] = ( rand()%2 * 2 ) + 2;//a[i][j] matrisinde rastgele seçilmiþ ve deðeri 0 olan bir elemanýn 
				}
			}
		}		
				
		if ( counter1 != 0 ){
			
			printf( "\n\n\n\n\n" );//Çýktýda sadece önceki ve þu anki aþamanýn görünmesi için matristeki deðerlerin gösterildiði kutular arasýnda 5 satýr boþluk býrakýlmasý 
			printf( "%c\n", eylem );//Hangi tuþa basýldýðýnýn çýktýda gösterilmesi
		}
	 
	}while ( counter != 0 && sonuc != 1 );//a[i][j] matrisinin bir elemaýný 2048 olmadýðý ve a[i][j] matrisinin tamamen dolup W,A,S,D tuþlarýndan herhangi birine basýldýðýnda matristeki elemanlar deðiþmediði sürece devam et
	
	return 0;
}

