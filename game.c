//2048 oyunun c dilinde kodlanmas�

#include <stdio.h>
#include <time.h>

int main(){
	srand(time(NULL));
	
	int i, j, a[100][100], k, l, sonuc = 0, score = 0, kontrol, n, t, sayac, b, counter, x, Satir[100], Sutun[100], R[100][100], scoreR, counter1 = 1, kontrol1, y, maxscore = 0, kontrol2;
	char eylem, Eylem[] = "WASDERX";
	
	for ( i = 1; i <= 8; i++ ){ //Ba�lang��ta matrisin b�t�n elemanlar�na 0 de�erinin atanmas�
		
		for ( j = 1; j <= 8; j++ ){
			
			a[i][j] = 0;
		} 
	}
	
	//4x4 boyundaki a[i][j] matrisinin rastgele iki eleman�na 2 veya 4 de�erinin atanmas�
	//Matrisin rastgele bir eleman�na 2 veya 4 de�erinin atanmas�
	i = rand()%4 + 1;//Rastgele bir sat�r se�ilmesi
	j = rand()%4 + 1;//Rasgele bir s�tun se�ilmesi
	
	a[i][j] = (rand()%2 + 1) * 2;//Se�ilen sat�r ve s�tunun oldu�u yere 2 veya 4 de�erinin rastgele atanmas�
	
	//2 veya 4 de�erinin atand��� ilk yere 2 veya 4 de�erinin yeniden atanmamas� i�in do...while d�ng�s�n�n kullan�lmas�
	do{
		
	k = rand()%4 + 1;
	l = rand()%4 + 1;
	
	a[k][l] = (rand()%2 + 1) * 2;
		
	}while ( k == i && l == j );//Se�ilen sat�r ve s�tun ilk rastgle de�erin atand��� sat�r ve s�tuna e�it oldu�u s�rece d�ng�ye devam et 
	
	do{
		
		if( counter1 != 0 ){
			
			sonuc = 0;//Matriste 2048 de�erinin olup olmad���n�n kontrol� i�in kullan�lan de�i�ken
			//Matristeki say�lar�n kutucuklar i�inde ekranda yazd�r�lmas�
			//Kutucuklar�n alt alta iki tane | karakterinin ve - karekterinin yan yana yazd�r�lmas�yla olu�mas�
			//Tek bir kutucuk i�in bir tane karekteri yazd�r�ld���nda matristeki say�yla beraber - karekteri yazd�r�ld���nda kutucuklar�n g�r�nt�s� bozuldu�u i�in iki tane alt alt | karekterinin yazd�r�lmas�
			//Matristeki say�lar�n yazd�r�lmas� i�in 8 sat�r ve 4 s�tun �eklindeki kutucuklar�n yazd�r�lmas�
			printf( "____________________\n" );
		
			for ( i = 1; i <= 8; i++ ){
		
				for( j = 1; j <= 4; j++ ){
			
					if ( i % 2 == 0 ){//Sat�r numaras� �ift ise kutucu�un i�inin bo� olarak g�sterilmesi
					
						printf( "|____" );
					}
					else{//Sat�r numaras� tek ise a[4][4] matrisindeki say�lar�n kutucuklar i�inde g�sterilemsi
					
						if ( a[i/2+1][j] == 0 ){//Matristeki eleman 0 ise kutucu�un i�ini bo� olarak g�ster
					
							printf( "|    " );
						}
					
						else{
						
							if ( a[i/2+1][j] == 2048 ){//Matristeki eleman 2048 ise sonuc de�i�kenine 1 de�erini ata
							
								sonuc = 1;
							}
							
							sayac = 1;//��kt�da g�sterilecek olan say�n�n sa��nda ne kadar bo�luk olaca��n�n hesaplanmas�na yarayan de�i�ken
							b = 10;//Matristeki say�n�n ka� basamakl� oldu�unu yani ��kt�da ne kadar yer kaplayaca��n� hesaplamak i�in kullan�lan de�i�ken
						
							//Rastgele atanan 2 veya 4 de�erinin ��ktada * karekteri ile birlikte g�sterilmesi
							if ( i/2+1 == Satir[x] && j == Sutun[x] ){//E�er i/2+1 ve j de�erleri rastgele atanan 2 veya 4 de�erinin bulundu�u sat�r ve s�tuna e�it ise bu de�eri * karekteri ile birlikte g�ster
							
								printf( "|%d*  ", a[i/2+1][j] );
							}
						
							else{//E�er rastgele atanan say� de�ilse
							
								while ( a[i/2+1][j] / b != 0 ){//Matristeki say�n�n basamak say�s�n�n hesaplanmas�
							
									b = b * 10;
									++sayac;
								}
							
								printf( "|%d", a[i/2+1][j] );
						
								for ( k = 1; k <= 4 - sayac; k++ ){//Matristeki say�n�n basamak say�s�na yani ekranda ne kadar yer kaplad���na ba�l� olarak sa��ndaki bo�luklar�n yazd�r�lmas�
							
									printf(" ");
								}
							}
						}
					}
				}
		
				printf( "|\n" );//Matristeki ilgili sat�rdaki b�t�n say�lar yazd�r�ld�ktan sonra alt sat�ra ge�
			}
			
			if (kontrol2 == 1 ){
				
				printf( "Highest Score: %d\n", maxscore );//En y�ksek skorun yazd�r�lmas�
			}
			
		}		
		
		//a[i][j] matrisindeki b�t�n elemanlar�n s�f�rdan farkl� olup olmad���n�n ve W,A,S,D tu�lar�ndan herhangi birine bas�ld���nda matrisin de�i�ip de�i�medi�inin kontrol edilmesi
		counter = 0;//W,A,S,D tu�lar�ndan herhangi birine bas�ld���nda matrisin b�t�n yerlerinin dolup dolmad���n� ve elemanlar�n yerlerinin de�i�ip de�i�medi�ini kontrol eden de�i�ken
		for ( i = 1; i <= 4; i++ ){
			
			for ( j = 1; j <= 4; j++ ){
				
				//a[i][j] matrisindeki ard���k elemanlar�n birbirine e�it olup olmad���na bak�lmas�
				if ( a[i][j] == a[i][j+1] || a[i][j] == a[i+1][j] ){//Matristeki ard���k elemanlar�n e�it olmas� halinde matristeki elemanlar hareket edebilecektir yani oyun hala devam edecektir
					
					++counter;
				}
				
				if ( a[i][j] == 0 ){//a[i][j] de�erinin 0 olup olmad���n�n kontrol�
					
					++counter;
				}
			}
		}
		
		if ( counter != 0 || sonuc != 1){
			
			kontrol1 = 0; 
			do{//W,A,S,D,E,R,X d���ndaki tu�lara bas�ld���nda herhangi bir i�lem�n yap�lmas�n�n engellenmesi
		
				eylem = getch();
				
				y = 0;
				while ( Eylem[y] != '\0' ){
					
					if ( eylem == Eylem[y] ){
						
						kontrol1 = 1;
					}
					++y;
				}
				
			}while( kontrol1 == 0 );
	
						
			if ( eylem == 'R' ){//R tu�una bas�ld���nda �nceki a�amaya d�n�lmesi
					
				score = scoreR;//scoreR de�i�keninde saklanan �nceki a�aman�n skorunun score de�i�kenine atanmas�
				for ( i = 1; i <= 4; i++ ){//�nceki a�amadaki a[i][j] matrisindeki de�erlerin sakland��� R[i][j] matrisindeki elemanlar�n a[i][j] matrisine atanmas�
						
					for ( j = 1; j <= 4; j++ ){
									
						a[i][j] = R[i][j];
					}
				}
			}
				
			else if ( eylem == 'X' ){// X tu�una bas�l�rsa a[i][j] matrisinin s�f�rlanmas� ve rastgele 2 eleman�na 2 veya 4 de�erinin rastgele se�ilerek de�erinin atanmas�
						
				score = 0;//skorun s�f�rlanmas�
				for ( i = 1; i <= 8; i++ ){//a[i][j] matrisindeki elemanlara 0 de�erinin atanmas�
			
					for ( j = 1; j <= 8; j++ ){
						
						a[i][j] = 0;
					} 
				}
				//Rastgele sat�r ve s�tun numaras�n�n se�ilip i ve j de�i�kenlerine atanmas�
				i = rand()%4 + 1;
				j = rand()%4 + 1;
				
				a[i][j] = (rand()%2 + 1) * 2;//Se�ilen i. sat�r ve j. s�tunda bulunan yere rastgele 2 veya 4 de�erinin atanmas�
				//2 veya 4 de�erinin atand��� ilk yere 2 veya 4 de�erinin yeniden atanmamas� i�in do...while d�ng�s�n�n kullan�lmas�
				do{
					
					k = rand()%4 + 1;
					l = rand()%4 + 1;
				
					a[k][l] = (rand()%2 + 1) * 2;
					
				}while ( k == i && l == j );//Se�ilen sat�r ve s�tun rastgle de�erin atand��� sat�r ve s�tuna e�it oldu�u s�rece d�ng�ye devam et 
			}
				
			else if ( eylem == 'E' ){//E tu�una bas�l�rsa d�ng�den ��kmak ve program�n sonlanmas� i�in sonuc de�i�kenine bir atanmas�
								
				sonuc = 1;
			}
				
			else if ( eylem == 'A' || ( eylem == 'W' || ( eylem == 'D' || eylem == 'S' ) ) ){
				
				for ( i = 1; i <= 4; i++ ){
					
					for ( j = 1; j <= 4; j++ ){
							
						R[i][j] = a[i][j];//�nceki a�amadak� matris elemanlar�n kaybolmamas� i�in R[i][j] matrisine atanmas�
						scoreR = score;//�nceki a�amadaki skorun de�erinin kaybolmamas� i�in scoreR de�i�kenine atanmas�
						//W,A,S,D tu�lar�na bas�ld���nda matrisin elemanlar�n�n belirtilen y�nde yerlerinin de�i�mesi i�in her bir tu� i�in ayr� bir kod yazmak yerine sadece A tu�una bas�ld���na yap�lacak i�leme g�re di�er tu�lar i�in matristeki elemanlar�n yerlerinin de�i�tirilmesi
						//Matrisin W tu�u i�in 90 derece, D tu�u i�in 180 derece, S tu�u i�in 270 derece saatin tersi y�n�de d�nd�r�lmesi
						//Matristeki elemanlar�n yerleri de�i�tirldi�inde atanan yerde bulunan eleman�n kaybolmamas� i�in elemanlar�n 1. ve 4. sat�rlar ile 1. ve 4. s�tunlar aras�nda bulunan matrise de�il 1. ve 4. sat�rlar ile 1. ve 4. s�tunlar aras�nda bulunan matrise atanmas�
						if ( eylem == 'A' ){
						
							a[i+4][j+4] = a[i][j];
						}
									
						else if ( eylem == 'W' ){//a[i][j]'nin saatin tersi y�n�nde 90 derece d�nd�lerek 4 ad�m sa�a 4 ad�m a�a�� kayd�r�lmas�
							
							a[9-j][i+4] = a[i][j];
						}
								
						else if ( eylem == 'D' ){//a[i][j]'nin saatin tersi y�n�nde 180 derece d�nd�lerek 4 ad�m sa�a 4 ad�m a�a�� kayd�r�lmas�
							
							a[9-i][9-j] = a[i][j];
						}
						
						else if ( eylem == 'S' ){//a[i][j]'nin saatin tersi y�n�nde 270 derece d�nd�lerek 4 ad�m sa�a 4 ad�m a�a�� kayd�r�lmas�
				
							a[j+4][9-i] = a[i][j];
						}
					}
				}
								
				//a[i][j] matrisinin her bir eleman�n bulundu�u sat�rda solundaki elemanlar 0 oldu�u s�rece sola kayd�r�lmas� ve solundaki eleman kendisine e�itse toplam�n�n soldaki yere atanmas�
				counter1 = 0;//W,A,S,D tu�lar�ndan herhangi birine bas�ld���nda matrisin elemanlar�n�n yerleri de�i�miyorsa ayn� a�aman�n ekrana bir daha yazd�r�lmamas� i�in kullan�lan de�i�ken
				for ( i = 5; i <= 8; i++ ){
				
					t = 4;//Her bir sat�rdaki yan yana e�it olan elemanlar�n toplam�yla elde edilen sonucun o sat�rdaki sonuca e�it olan ba�ka bir say�yla toplanmas�n� engellemek i�in kullan�lan de�i�ken
						
					for ( j = 5; j <= 8; j++ ){
						
						if ( a[i][j] != 0 ){//Matristeki 0 olan elemanlar�n kar��la�t�r�lmas�na gerek olmad��� i�in sadece 0'dan farkl� olan elemanlara bak�lmas�
						
							k = j;//a[i][j] eleman�n�n solundaki elemanlarla kar��la�t�r�lmas� i�in kullan�nlan de�i�ken
								
							while ( k > t + 1 ){//Kar��la�t�r�lacak olan a[i][j] eleman�n�n o sat�rdaki toplanm�� olan de�erle tekrardan toplanmas�n�n �nlenmesi
									
								if ( a[i][k] == a[i][k-1] ){//a[i][k] ile a[i][[k-1] e�itse toplamlar�n� a[i][k-1]'e ata
										
									a[i][k-1] = a[i][k-1] + a[i][k];
									a[i][k] = 0;
									score = score + a[i][k-1];//Skorun hesaplanmas�
									--k;
									t = k;//Toplanan de�erin atand��� s�tun numaras�n�n t de�i�keninde saklanmas�
									++counter1;
								}
								
								else if ( a[i][k-1] == 0 ){//a[i][k] de�erinin solundaki eleman 0 ise sola kayd�r
										
									//a[i][k] ile a[i][k-1]'in de�erlerinin yerlerinin de�i�tirlmesi
									a[i][k-1] = a[i][k];
	 								a[i][k] = 0;
									--k;
									++counter1;
								}
										
								else{//De�ilse sonraki elemana ge�
							
									--k;
								}
							}
						}
					}
				}
				
				kontrol2 = 0;
				if ( score > maxscore ){//Daha y�ksek bir skora ula��ld���nda skorun maxscore de�i�keninde saklanmas�
					
					maxscore = score;
					kontrol2 = 1;
				}
				
				//Elemanlar�n yerlerinin de�i�tirilmesi i�in yap�lan i�lemin tersi yap�larak say�lar 1. ve 4. sat�rlar ile 1. ve 4. s�tunlar aras�nda bulunan matrise atanarak yerlerinin d�zeltilmesi
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
						
					//a[i][j] matrisindeki de�eri 0 olan rastele bir elemana 2 veya 4 de�erinin rastgele atanmas�
					k = 0;
					for ( i = 1; i <= 4; i++ ){
						
						for ( j = 1; j <= 4; j++ ){
							
							if ( a[i][j] == 0 ){
							
								Satir[k] = i;//a[i][j] matrisinde de�eri 0 olan eleman�n sat�r numaras�n�n Satir[k] dizine atanmas�
								Sutun[k] = j;//De�eri 0 olan eleman�n s�tun numaras�n�n Sutun[k] dizine atanmas�
								++k;
							}
						}
					}		
						
					x = rand()%k;//a[i][j] matrisindeki 0 olan elemalar�n sat�r ve s�tun numaralar�n� saklayan Satir[k] ve Sutun[k] dizilerindeki elemanlar�n s�ra numaras�n� g�steren 0 ile k-1 aras�ndaki de�erlerden rastgele birinin x de�i�kenine atanmas�
					a[Satir[x]][Sutun[x]] = ( rand()%2 * 2 ) + 2;//a[i][j] matrisinde rastgele se�ilmi� ve de�eri 0 olan bir eleman�n 
				}
			}
		}		
				
		if ( counter1 != 0 ){
			
			printf( "\n\n\n\n\n" );//��kt�da sadece �nceki ve �u anki a�aman�n g�r�nmesi i�in matristeki de�erlerin g�sterildi�i kutular aras�nda 5 sat�r bo�luk b�rak�lmas� 
			printf( "%c\n", eylem );//Hangi tu�a bas�ld���n�n ��kt�da g�sterilmesi
		}
	 
	}while ( counter != 0 && sonuc != 1 );//a[i][j] matrisinin bir elema�n� 2048 olmad��� ve a[i][j] matrisinin tamamen dolup W,A,S,D tu�lar�ndan herhangi birine bas�ld���nda matristeki elemanlar de�i�medi�i s�rece devam et
	
	return 0;
}

