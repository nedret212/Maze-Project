#include <iostream>
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

///140202121 - Selda Yapal
///150202114 - Nedret Gegeoglu

struct dugum  {

	int koordinat[2];
	int check;
	struct dugum* sonraki;
	struct dugum* onceki;
};
struct dugum* ilk;

struct dugum* ekle(int x,int y,int c) {
	struct dugum* yeni
		= (struct dugum*)malloc(sizeof(struct dugum));
	yeni->koordinat[0] = x;
	yeni->koordinat[1] = y;
	yeni->check=c;
	yeni->onceki = NULL;
	yeni->sonraki = NULL;
	return yeni;
}
void sona_ekle(int x,int y,int c);
void listeden_sil();
void son_eleman(int x,int y){
    struct dugum* temp = ilk;
    while(temp->sonraki!= NULL) {
		temp = temp->sonraki;
	}
	printf("son eleman: [%d,%d]\n",temp->koordinat[0],temp->koordinat[1]);

	x=temp->koordinat[0];
	y=temp->koordinat[1];
}
void listeyi_yazdir();
int listede_var_mi(int satir, int sutun);
void matris();
void labirent(int boyut,int matrix[][50],int cikis_satir,int cikis_sutun){
    int i,j,k,c;
    /*printf("\n\nfonksiyona aktarilan matris degerleri:\n");
    for(i=0;i<boyut;i++)
    {
        for(j=0;j<boyut;j++)
        {
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }*/

    initwindow(1000,700,"Labirent");
    setbkcolor(15);


    /* setcolor(WHITE);
    bar(10,10,690,490);*/

    ///TOOLBAR
    for(i=5;i<=10;i++)
    {
        for(j=5;j<=995;j++)
        {
            putpixel(j,i,RED);
        }
    }
    for(i=5;i<=695;i++)
    {
        for(j=5;j<=10;j++)
        {
            putpixel(j,i,RED);
        }
    }
    for(i=5;i<=695;i++)
    {
        for(j=990;j<=995;j++)
        {
            putpixel(j,i,RED);
        }
    }
    for(i=690;i<=695;i++)
    {
        for(j=5;j<=995;j++)
        {
            putpixel(j,i,RED);
        }
    }
    int sutun=990/boyut;
    int satir=690/boyut;

    ///MATRISE UYGUN LABIRENT HAZIRLAMA & RENKLENDIRME
    for(i=0;i<boyut;i++)
    {
        for(j=0;j<boyut;j++)
        {
            if(matrix[i][j]==0)///siyah ciz
            {
                if(j==boyut-1)
                {
                    for(k=(i*satir)+10;k<(i*satir)+satir;k++)
                    for(c=(j*sutun)+10;c<(j*sutun)+sutun;c++)
                    putpixel(c,k,BLACK);

                }
                else
                {
                    for(k=(i*satir)+10;k<(i*satir)+satir+10;k++)
                    for(c=(j*sutun)+10;c<(j*sutun)+sutun+10;c++)
                    putpixel(c,k,BLACK);

                }

            }
            if(matrix[i][j]==1)///beyaz ciz
            {
                if(j==boyut-1)
                {
                    for(k=(i*satir)+10;k<(i*satir)+satir+10;k++)
                    for(c=(j*sutun)+10;c<(j*sutun)+sutun+5;c++)
                    putpixel(c,k,15);


                    if(j==11)
                    {
                    for(k=(i*satir)+10;k<(i*satir)+satir+10;k++)
                    for(c=(j*sutun)+10;c<(j*sutun)+13;c++)
                    putpixel(c,k,5);

                    for(k=(i*satir)+10;k<(i*satir)+15;k++)
                    for(c=(j*sutun)+10;c<(j*sutun)+13;c++)
                    putpixel(c,k,5);
                    }
                    else
                    {
                    ///kutu haline getir
                    for(k=(i*satir)+10;k<(i*satir)+satir+10;k++)
                    for(c=(j*sutun)+10;c<(j*sutun)+13;c++)
                    putpixel(c,k,j);

                    for(k=(i*satir)+10;k<(i*satir)+13;k++)
                    for(c=(j*sutun)+10;c<(j*sutun)+sutun+5;c++)
                    putpixel(c,k,j);
                    }

                }
                else
                {
                    for(k=(i*satir)+10;k<(i*satir)+satir+10;k++)
                    for(c=(j*sutun)+10;c<(j*sutun)+sutun+10;c++)
                    putpixel(c,k,15);

                    if(j==11)
                    {
                        ///kutu haline getir
                    for(k=(i*satir)+10;k<(i*satir)+satir+10;k++)
                    for(c=(j*sutun)+10;c<(j*sutun)+15;c++)
                    putpixel(c,k,5);

                    for(k=(i*satir)+10;k<(i*satir)+13;k++)
                    for(c=(j*sutun)+10;c<(j*sutun)+sutun+15;c++)
                    putpixel(c,k,5);
                    }
                    else
                    {
                    ///kutu haline getir
                    for(k=(i*satir)+10;k<(i*satir)+satir+10;k++)
                    for(c=(j*sutun)+10;c<(j*sutun)+13;c++)
                    putpixel(c,k,j);

                    for(k=(i*satir)+10;k<(i*satir)+13;k++)
                    for(c=(j*sutun)+10;c<(j*sutun)+sutun+10;c++)
                    putpixel(c,k,j);
                    }
                }
            }
        }
    }

    readimagefile("resim/cheese.jpg",(cikis_sutun*sutun)+15,(cikis_satir*satir)+15,(cikis_sutun*sutun)+(sutun),(cikis_satir*satir)+(satir));
    Sleep(500);

    ///dinamik fotograf yerlestirme
    struct dugum* temp = ilk;
    readimagefile("resim/mice.jpg",(temp->koordinat[1]*sutun)+15,(temp->koordinat[0]*satir)+15,(temp->koordinat[1]*sutun)+(sutun),(temp->koordinat[0]*satir)+(satir));
    Sleep(500);

	while(temp != NULL) {
		//printf("[%d,%d]",temp->koordinat[0],temp->koordinat[1]);
		temp = temp->sonraki;

		readimagefile("resim/mice.jpg",(temp->koordinat[1]*sutun)+15,(temp->koordinat[0]*satir)+15,(temp->koordinat[1]*sutun)+(sutun),(temp->koordinat[0]*satir)+(satir));
		Sleep(500);

		if(temp->sonraki==NULL)
            break;
	}

}

int main()
{
	matris();

	return 0;
}

void matris(){
    int i, j;
    int boyut;
    srand(time(NULL));
    int rastgele=rand()%2;
	/*int matris[13][13] = {

	1,1,1,0,0,1,1,1,1,1,0,1,1,
	0,1,1,1,0,0,0,0,1,1,1,1,1,
	1,0,0,1,1,1,1,1,1,0,1,1,1,
	1,1,1,1,1,0,0,0,1,0,0,1,0,
	1,1,0,1,1,0,0,0,1,0,1,1,0,
	1,1,0,0,0,0,1,1,1,1,1,0,0,
	1,0,0,1,0,1,1,0,1,0,0,0,0,
	1,1,1,0,1,1,0,0,1,1,1,1,0,
	0,0,1,1,1,1,1,1,0,1,0,1,1,
	0,0,1,0,0,1,0,1,1,0,1,1,0,
	1,1,1,1,1,1,0,0,1,1,1,0,0,
	1,0,1,0,1,1,0,1,1,1,1,1,0,
	1,1,1,1,0,0,1,0,0,0,0,1,1,
	};*/
	///Girilen boyuta gore rastgele matris olusturur
	printf("matris boyutunu gir: ");
	scanf("%d",&boyut);
	printf("\n\n");
	int matris[boyut][boyut];
	for(i=0;i<boyut;i++)
    {
        for(j=0;j<boyut;j++)
        {
            rastgele=rand()%2;
            matris[i][j]=rastgele;
        }
    }
    int yedek_matris[boyut][50];
    ///olusturulan matrisi yedek matrise aktariyoruz
    for(i=0;i<boyut;i++)
    {
        for(j=0;j<boyut;j++)
        {
            yedek_matris[i][j]=matris[i][j];
        }
    }

	printf("\t");
	for(i=0;i<boyut;i++)
        printf("%d|\t",i);

        printf("\n");
        for(i=0;i<boyut;i++)
        printf("_________");

        printf("\n");
	for (i = 0; i < boyut; i++)
	{
	    printf("%2d|\t",i);
		for (j = 0; j < boyut; j++)
		{
			printf("%d\t", matris[i][j]);
		}
		printf("\n");
	}
    ///labirente uygun giris cikis kapisi belirle, kontrol et
	int giris[2], cikis[2];
	printf("\ngiris kapisi gir [satir,sutun]: ");
	scanf("%d %d", &giris[0],&giris[1]);

	printf("cikis kapisi gir [satir,sutun]: ");
	scanf("%d %d", &cikis[0],&cikis[1]);


	while(matris[giris[0]][giris[1]]!=1 || matris[cikis[0]][cikis[1]]!=1)
    {
        printf("labirente uygun giris cikis degeri girmediniz!\n");

        printf("giris kapisi gir [satir,sutun]: ");
        scanf("%d %d", &giris[0],&giris[1]);

        printf("cikis kapisi gir [satir,sutun]: ");
        scanf("%d %d", &cikis[0],&cikis[1]);
    }

    printf("\ngiris: [%d,%d]\ncikis: [%d,%d]\n", giris[0],giris[1],cikis[0],cikis[1]);
    int sonuc[2];
    int liste_indis=0;

    ilk = NULL;
    ///giris degerlerini sonuca aktardik
    sonuc[0]=giris[0];
    sonuc[1]=giris[1];
    sona_ekle(sonuc[0],sonuc[1],1);
    liste_indis++;

    int liste_kontrol=0;
    int a=0;
    int kontrol=0;

    int alt_check=0, ust_check=0, sag_check=0, sol_check=0;
    int toplam_check=0;
    int toplam_gidilen_komsu=0;
    int ekle_kontrol=0;
    int cikis_yok[2];
    int cikis_kontrol=0;
    int son_eleman_kontrol[2];
    int son_eleman_degeri[2];
    int son_eleman_indis=0;
    int ilk_tur=0;
    int hatali_cikis=0;

    ///labirent dongusu cikisa ulasildiginda donguden cikar
    while(kontrol!=1)
    {
    if(sonuc[0]>=0 && sonuc[1]>=0 && sonuc[0]<boyut && sonuc[1]<boyut)
    {
        alt_check=0; ust_check=0; sol_check=0; sag_check=0; toplam_check=0;
        ///girilen elemanin listede olup olmadigini gosterir
        /*liste_kontrol=listede_var_mi(0,0);

        if(liste_kontrol==1)
            printf("listede var check: 1\n");
        else if(liste_kontrol==0)
            printf("listede yok check: 0\n");*/

            ///alta git
            if((sonuc[0]>=0 && sonuc[1]>=0 && sonuc[0]<boyut && sonuc[1]<boyut)&&matris[sonuc[0]+1][sonuc[1]]==1)
                alt_check=1;

            ///saga git
            if((sonuc[0]>=0 && sonuc[1]>=0 && sonuc[0]<boyut && sonuc[1]<boyut)&&matris[sonuc[0]][sonuc[1]+1]==1)
                sag_check=1;

            ///sola git
            if((sonuc[0]>=0 && sonuc[1]>=0 && sonuc[0]<boyut && sonuc[1]<boyut)&&matris[sonuc[0]][sonuc[1]-1]==1)
                sol_check=1;

            ///uste git
            if((sonuc[0]>=0 && sonuc[1]>=0 && sonuc[0]<boyut && sonuc[1]<boyut)&&matris[sonuc[0]-1][sonuc[1]]==1)
                ust_check=1;

        toplam_check = alt_check+ust_check+sol_check+sag_check;

        /// GIDILECEK TEK 1 DURUM VARSA
        if(toplam_check==1 && (sonuc[0]>=0 && sonuc[1]>=0 && sonuc[0]<boyut && sonuc[1]<boyut))
        {
            printf("\n1. durum toplam check: %d\n",toplam_check);
            liste_kontrol=listede_var_mi(sonuc[0],sonuc[1]);
            if(liste_kontrol==1)
            {
                matris[sonuc[0]][sonuc[1]]=0;
            }
            if(alt_check==1)
            {
                sonuc[0]++;
                sona_ekle(sonuc[0],sonuc[1],1);
                toplam_check=0;
            }
            if(sag_check==1)
            {
                sonuc[1]++;
                sona_ekle(sonuc[0],sonuc[1],1);
                toplam_check=0;
            }
            if(sol_check==1)
            {
                sonuc[1]--;
                sona_ekle(sonuc[0],sonuc[1],1);
                toplam_check=0;
            }
            if(ust_check==1)
            {
                sonuc[0]--;
                sona_ekle(sonuc[0],sonuc[1],1);
                toplam_check=0;
            }
            listeyi_yazdir();
        }
        /// GIDILECEK 1 DEN FAZLA DURUM VARSA
        if(toplam_check>1 && (sonuc[0]>=0 && sonuc[1]>=0 && sonuc[0]<boyut && sonuc[1]<boyut))
        {
            toplam_check=0;
            toplam_gidilen_komsu=0;
            ekle_kontrol=0;

            /// ETRAFINDAKI KOMSULARIN HEPSI DAHA ONCE GIDILMIS ISE

            ///alta git
            if(matris[sonuc[0]+1][sonuc[1]]==1){
                alt_check=1;
                toplam_check+=alt_check;

                liste_kontrol=listede_var_mi(sonuc[0]+1,sonuc[1]);
                if(liste_kontrol==1)
                toplam_gidilen_komsu++;
                ///ileride bunlara ihtiyac olarak yon degiskenleri de belirlenebilir
                ///( gidilen alt komsu, gidilen ust komsu gibi)
            }
            ///saga git
            if(matris[sonuc[0]][sonuc[1]+1]==1){
                sag_check=1;
                toplam_check+=sag_check;

                liste_kontrol=listede_var_mi(sonuc[0],sonuc[1]+1);
                if(liste_kontrol==1)
                toplam_gidilen_komsu++;
            }
            ///sola git
            if(matris[sonuc[0]][sonuc[1]-1]==1){
                sol_check=1;
                toplam_check+=sol_check;

                liste_kontrol=listede_var_mi(sonuc[0],sonuc[1]-1);
                if(liste_kontrol==1)
                toplam_gidilen_komsu++;
            }
            ///uste git
            if(matris[sonuc[0]-1][sonuc[1]]==1){
                ust_check=1;
                toplam_check+=ust_check;

                liste_kontrol=listede_var_mi(sonuc[0]-1,sonuc[1]);
                if(liste_kontrol==1)
                toplam_gidilen_komsu++;
            }


            printf("toplam check: %d\ttoplam gidilen komsu: %d\n",toplam_check,toplam_gidilen_komsu);
            /// ETRAFINDAKI KOMSULARIN HEPSI DAHA ONCE GIDILMIS ISE

            if(toplam_check==toplam_gidilen_komsu)
            {
                matris[sonuc[0]][sonuc[1]]=0;
                listeden_sil();
                son_eleman(sonuc[0],sonuc[1]);
                                                                            ///BURAYI AC
                printf("son eleman: [%d,%d]",sonuc[0],sonuc[1]);

                ///BURADAYIM
            }

            printf("\n2. durum toplam check: %d\n",toplam_check);

            liste_kontrol=listede_var_mi(sonuc[0]+1,sonuc[1]);
            if(alt_check==1 && liste_kontrol==0 && ekle_kontrol==0)
            {
                sonuc[0]++;
                sona_ekle(sonuc[0],sonuc[1],1);
                ekle_kontrol=1;
            }

            liste_kontrol=listede_var_mi(sonuc[0],sonuc[1]+1);
            if(sag_check==1 && liste_kontrol==0 && ekle_kontrol==0)
            {
                sonuc[1]++;
                sona_ekle(sonuc[0],sonuc[1],1);
                ekle_kontrol=1;
            }

            liste_kontrol=listede_var_mi(sonuc[0],sonuc[1]-1);
            if(sol_check==1 && liste_kontrol==0 && ekle_kontrol==0)
            {
                sonuc[1]--;
                sona_ekle(sonuc[0],sonuc[1],1);
                ekle_kontrol=1;
            }

            liste_kontrol=listede_var_mi(sonuc[0]-1,sonuc[1]);
            if(ust_check==1 && liste_kontrol==0 && ekle_kontrol==0)
            {
                sonuc[0]--;
                sona_ekle(sonuc[0],sonuc[1],1);
                ekle_kontrol=1;
            }

            listeyi_yazdir();
        }

        printf("%d. tur sonuc: [%d,%d]check: \n",a,sonuc[0],sonuc[1]);
        a++;

        if(sonuc[0]==cikis[0] && sonuc[1]==cikis[1])
            kontrol=1;


        ///ayni son eleman ust uste 500 defa geldiginde cikis yoktur
        if(ilk_tur==0){
            son_eleman_degeri[0]=sonuc[0];
            son_eleman_degeri[1]=sonuc[1];
        }/*
        printf("%d. tur son eleman degeri[0]: %d\tsonuc[0]: %d\n",ilk_tur,son_eleman_degeri[0],sonuc[0]);
        printf("%d. tur son eleman degeri[1]: %d\tsonuc[1]: %d\n\n",ilk_tur,son_eleman_degeri[1],sonuc[1]);
*/
        if(son_eleman_degeri[0]==sonuc[0] && son_eleman_degeri[1]==sonuc[1])
            hatali_cikis++;

        else if(son_eleman_degeri[0]!=sonuc[0] || son_eleman_degeri[1]!=sonuc[1]){
            son_eleman_degeri[0]=sonuc[0];
            son_eleman_degeri[1]=sonuc[1];
            hatali_cikis=0;
        }
        if(hatali_cikis==500)
        {
            printf("\nLabirentin cikisi yok!\n");
            break;
        }
        ilk_tur++;

        }
        ///eger sinirlarin disina tasmissa
        if(sonuc[0]<0 || sonuc[1]<0 || sonuc[0]>=boyut || sonuc[1]>=boyut)
        {
            ///sonuc0 sonuc1 e deger ata (onceki deger)

            matris[sonuc[0]][sonuc[1]]=0;
            listeden_sil();
            son_eleman(sonuc[0],sonuc[1]);
                                                                        ///BURAYI AC
            printf("son eleman: [%d,%d]\n",sonuc[0],sonuc[1]);
            ///ondan onceki hamleye gonder
            ///burayi sifirla

            ///ust tasma
            if(sonuc[0]<0)
            {
                sonuc[0]++;
                sona_ekle(sonuc[0],sonuc[1],1);
                toplam_check=0;
            }
            ///sola tasma
            else if(sonuc[1]<0)
            {
                sonuc[1]++;
                sona_ekle(sonuc[0],sonuc[1],1);
                toplam_check=0;
            }
            ///saga tasma
            else if(sonuc[1]>=boyut)
            {
                sonuc[1]--;
                sona_ekle(sonuc[0],sonuc[1],1);
                toplam_check=0;
            }
            ///alta tasma
            else if(sonuc[0]>=boyut)
            {
                sonuc[0]--;
                sona_ekle(sonuc[0],sonuc[1],1);
                toplam_check=0;
            }
        }

    }
    if(hatali_cikis!=500){
        printf("Labirentin sonuna ulasildi\n");
        listeyi_yazdir();
    }

    if(hatali_cikis!=500)
    {
        labirent(boyut,yedek_matris,cikis[0],cikis[1]);
        while(1)
        {

        }
    }
}
int listede_var_mi(int satir, int sutun){
    struct dugum* temp = ilk;
    if(temp->koordinat[0]==satir && temp->koordinat[1]==sutun)
    {
        return 1;
    }
    while(temp->sonraki!= NULL) {
		temp = temp->sonraki;

		if(temp->koordinat[0]==satir && temp->koordinat[1]==sutun)
        {
            return 1;
        }
	}
        return 0;

}
void sona_ekle(int x,int y,int c) {
    int kontrol=0;
	struct dugum* temp = ilk;
	struct dugum* yeni = ekle(x,y,c);
	if(ilk == NULL) {
		ilk = yeni;
		return;
	}
	while(temp->sonraki != NULL) temp = temp->sonraki;

    temp->sonraki = yeni;
    yeni->onceki = temp;

}
void listeden_sil(){
    struct dugum* temp=ilk;
    if(ilk==NULL)
    {
        printf("liste bos!\n");
        return void();
    }
    else
    {
        while(temp->sonraki->sonraki!=NULL)
        temp=temp->sonraki;

        free(temp->sonraki);
        temp->sonraki=NULL;
    }
}
void listeyi_yazdir() {
	struct dugum* temp = ilk;
	printf("liste: ");
	while(temp != NULL) {
		printf("[%d,%d]",temp->koordinat[0],temp->koordinat[1]);
		temp = temp->sonraki;
	}
	printf("\n");
}
