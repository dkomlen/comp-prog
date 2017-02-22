#include<stdio.h>
#include<math.h>

typedef struct {
    char ime[32 + 1];
    char prezime[32 + 1];
    float ocjena[4];

} Clanovi;

void izracunajProsjek(Clanovi *prvi, Clanovi *drugi, Clanovi *treci) {

    float prosjekPrve = 0;
    float prosjekDruge = 0;
    float prosjekTrece = 0;
    float prosjekCetvrte = 0;

    prosjekPrve = prvi->ocjena[0] + drugi->ocjena[0] + treci->ocjena[0];
    prosjekDruge = prvi->ocjena[1] + drugi->ocjena[1] + treci->ocjena[1];
    prosjekTrece = prvi->ocjena[2] + drugi->ocjena[2] + treci->ocjena[2];
    prosjekCetvrte = prvi->ocjena[3] + drugi->ocjena[3] + treci->ocjena[3];

    prosjekPrve = prosjekPrve / 3;
    prosjekDruge = prosjekDruge / 3;
    prosjekTrece = prosjekTrece / 3;
    prosjekCetvrte = prosjekCetvrte / 3;

    printf("\nProsjecna ocjena (1.)Agatha Christie-Otrovno pero je %.2f", prosjekPrve);
    printf("\nProsjecna ocjena (2.)Markus Zusak-Kradljivica knjiga %.2f", prosjekDruge);
    printf("\nProsjecna ocjena (3.)Cecelia Ahern-Na kraju duge je %.2f", prosjekTrece);
    printf("\nProsjecna ocjena (4.)Simon Sebag Montefiore-Enigma je %.2f", prosjekCetvrte);

}

void izracunajBrojOcjena(Clanovi *prvi, Clanovi *drugi, Clanovi *treci) {

    int i = 0;
    int prvaKnjigaOcjene[5] = {0};

    float prosjekPrve = 0;
    float prosjekDruge = 0;
    float prosjekTrece = 0;
    float prosjekCetvrte = 0;

    //Za svako od 4 knjige izracunaj broj ocjena od svakog clana
    for (i = 0; i < 4; ++i) {

        int brojOcjena[6]; //ignoriramo ocjenu 0
        brojOcjena[1] = 0;
        brojOcjena[2] = 0;
        brojOcjena[3] = 0;
        brojOcjena[4] = 0;
        brojOcjena[5] = 0;

        int ocjenaPrvogClana = prvi->ocjena[i];
        brojOcjena[ocjenaPrvogClana] += 1;

        int ocjenaDrugogClana = prvi->ocjena[i];
        brojOcjena[ocjenaDrugogClana] += 1;

        int ocjenaTrecegClana = prvi->ocjena[i];
        brojOcjena[ocjenaTrecegClana] += 1;

        //Ispis ocjena
        printf("\nBroj ocjena %d. knjige: Odlican(5): %d, Vrlo dobar(4): %d, Dobar(3): %d, Dovoljan(2): %d, Nedovoljan(1) :%d", i + 1, brojOcjena[1], brojOcjena[2], brojOcjena[3], brojOcjena[4], brojOcjena[5]);

    }

}

main() {

    Clanovi unosPodataka1;
    Clanovi unosPodataka2;
    Clanovi unosPodataka3;


    printf("Anketa o knjigama");
    printf("\nPopis knjiga: ");
    printf("\n\n(1.)Agatha Christie-Otrovno pero \n(2.)Markus Zusak-Kradljivica knjiga \n(3.)Cecelia Ahern-Na kraju duge \n(4.)Simon Sebag Montefiore-Enigma");

    //1.clan
    printf("\n\nUnesite ime prvog clana: ");
    scanf(" %s", &unosPodataka1.ime);
    printf("Unesite prezime prvog clana: ");
    scanf(" %s", &unosPodataka1.prezime);

    do {

        printf("\nOcjenite prvu knjigu: ");
        scanf(" %f", &unosPodataka1.ocjena[0]);
        if (unosPodataka1.ocjena[0] < 0 || unosPodataka1.ocjena[0] > 5) {
            printf("Ocjena mora biti od 1-5!");
        }
    } while (unosPodataka1.ocjena[0] < 0 || unosPodataka1.ocjena[0] > 5);

    do {
        printf("Ocjenite drugu knjigu: ");
        scanf(" %f", &unosPodataka1.ocjena[1]);
        if (unosPodataka1.ocjena[1] < 0 || unosPodataka1.ocjena[1] > 5) {
            printf("Ocjena mora biti od 1-5!");
        }
    } while (unosPodataka1.ocjena[1] < 0 || unosPodataka1.ocjena[1] > 5);

    do {
        printf("Ocjenite trecu knjigu: ");
        scanf(" %f", &unosPodataka1.ocjena[2]);
        if (unosPodataka1.ocjena[2] < 0 || unosPodataka1.ocjena[2] > 5) {
            printf("Ocjena mora biti od 1-5!");
        }
    } while (unosPodataka1.ocjena[2] < 0 || unosPodataka1.ocjena[2] > 5);

    do {
        printf("Ocjenite cetvrtu knjigu: ");
        scanf(" %f", &unosPodataka1.ocjena[3]);
        if (unosPodataka1.ocjena[3] < 0 || unosPodataka1.ocjena[3] > 5) {
            printf("Ocjena mora biti od 1-5!");
        }
    } while (unosPodataka1.ocjena[3] < 0 || unosPodataka1.ocjena[3] > 5);

    //2.clan
    printf("\n\nUnesite ime drugog clana: ");
    scanf(" %s", &unosPodataka2.ime);
    printf("Unesite prezime drugog clana: ");
    scanf(" %s", &unosPodataka2.prezime);

    do {

        printf("\nOcjenite prvu knjigu: ");
        scanf(" %f", &unosPodataka2.ocjena[0]);
        if (unosPodataka2.ocjena[0] < 0 || unosPodataka2.ocjena[0] > 5) {
            printf("Ocjena mora biti od 1-5!");
        }
    } while (unosPodataka2.ocjena[0] < 0 || unosPodataka2.ocjena[0] > 5);

    do {
        printf("Ocjenite drugu knjigu: ");
        scanf(" %f", &unosPodataka2.ocjena[1]);
        if (unosPodataka2.ocjena[1] < 0 || unosPodataka2.ocjena[1] > 5) {
            printf("Ocjena mora biti od 1-5!");
        }
    } while (unosPodataka2.ocjena[1] < 0 || unosPodataka2.ocjena[1] > 5);

    do {
        printf("Ocjenite trecu knjigu: ");
        scanf(" %f", &unosPodataka2.ocjena[2]);
        if (unosPodataka2.ocjena[2] < 0 || unosPodataka2.ocjena[2] > 5) {
            printf("Ocjena mora biti od 1-5!");
        }
    } while (unosPodataka2.ocjena[2] < 0 || unosPodataka2.ocjena[2] > 5);

    do {
        printf("Ocjenite cetvrtu knjigu: ");
        scanf(" %f", &unosPodataka2.ocjena[3]);
        if (unosPodataka2.ocjena[3] < 0 || unosPodataka2.ocjena[3] > 5) {
            printf("Ocjena mora biti od 1-5!");
        }
    } while (unosPodataka2.ocjena[3] < 0 || unosPodataka2.ocjena[3] > 5);

    //3.clan
    printf("\n\nUnesite ime treceg clana: ");
    scanf(" %s", &unosPodataka3.ime);
    printf("Unesite prezime treceg clana: ");
    scanf(" %s", &unosPodataka3.prezime);
    do {

        printf("\nOcjenite prvu knjigu: ");
        scanf(" %f", &unosPodataka3.ocjena[0]);
        if (unosPodataka3.ocjena[0] < 0 || unosPodataka3.ocjena[0] > 5) {
            printf("Ocjena mora biti od 1-5!");
        }
    } while (unosPodataka3.ocjena[0] < 0 || unosPodataka3.ocjena[0] > 5);

    do {
        printf("Ocjenite drugu knjigu: ");
        scanf(" %f", &unosPodataka3.ocjena[1]);
        if (unosPodataka3.ocjena[1] < 0 || unosPodataka3.ocjena[1] > 5) {
            printf("Ocjena mora biti od 1-5!");
        }
    } while (unosPodataka3.ocjena[1] < 0 || unosPodataka3.ocjena[1] > 5);

    do {
        printf("Ocjenite trecu knjigu: ");
        scanf(" %f", &unosPodataka3.ocjena[2]);
        if (unosPodataka3.ocjena[2] < 0 || unosPodataka3.ocjena[2] > 5) {
            printf("Ocjena mora biti od 1-5!");
        }
    } while (unosPodataka3.ocjena[2] < 0 || unosPodataka3.ocjena[2] > 5);

    do {
        printf("Ocjenite cetvrtu knjigu: ");
        scanf(" %f", &unosPodataka3.ocjena[3]);
        if (unosPodataka3.ocjena[3] < 0 || unosPodataka3.ocjena[3] > 5) {
            printf("Ocjena mora biti od 1-5!");
        }
    } while (unosPodataka3.ocjena[3] < 0 || unosPodataka3.ocjena[3] > 5);



    printf("\n\n\tEVIDENCIJA:");
    printf("\nIme \tPrezime: ");
    printf("\n%s \t %s ", unosPodataka1.ime, unosPodataka1.prezime);
    printf("\nKorisnik je knjige ocjenio ovako: \n1.knjiga: %.2f \n2.knjiga: %.2f \n3.knjiga: %.2f \n4.knjiga: %.2f", unosPodataka1.ocjena[0], unosPodataka1.ocjena[1],
            unosPodataka1.ocjena[2], unosPodataka1.ocjena[3]);

    printf("\n%s \t %s ", unosPodataka2.ime, unosPodataka2.prezime);
    printf("\nKorisnik je knjige ocjenio ovako: \n1.knjiga: %.2f \n2.knjiga: %.2f \n3.knjiga: %.2f \n4.knjiga: %.2f", unosPodataka2.ocjena[0], unosPodataka2.ocjena[1],
            unosPodataka2.ocjena[2], unosPodataka2.ocjena[3]);
    printf("\n%s \t %s ", unosPodataka3.ime, unosPodataka3.prezime);
    printf("\nKorisnik je knjige ocjenio ovako: \n1.knjiga: %.2f \n2.knjiga: %.2f \n3.knjiga: %.2f \n4.knjiga: %.2f", unosPodataka3.ocjena[0], unosPodataka3.ocjena[1],
            unosPodataka3.ocjena[2], unosPodataka3.ocjena[3]);

    izracunajBrojOcjena(&unosPodataka1, &unosPodataka2, &unosPodataka3);

    int a;
    scanf("%d", &a);
}