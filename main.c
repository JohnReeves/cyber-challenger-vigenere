#include <stdio.h>
#include <string.h>

char cyphertext[]="WKH HDVLHVW PHWKRG RI HQFLSKHULQJ D WHAW PHVVDJH LV WR UHSODFH HDFK FKDUDFWHU EB DQRWKHU XVLQJ D ILAHG UXOH, VR IRU HADPSOH HYHUB OHWWHU D PDB EH UHSODFHG EB G, DQG HYHUB OHWWHU E EB WKH OHWWHU H DQG VR RQ.";
char alphabet[]="abcdefghijklmnopqrstuvwxyz";

// affine letter shift = (a*x + b) % 26
// thus the caesar letter shift = (1*x + a) % 26
int shift = 23; 

int a = 5;
int b = 3;

// vigenere cipher uses a keyword to give
// the shift for each letter in the message
// (the key is moved along the message)
char keyword[]="babacabab";

int main(void) 
{
    int i;
    char * name = "Your Name\0";

    printf("Hello %s, ", name);

    // removing spaces, printing forward
    for (i = 0; i < strlen(name); i++) {
      if (name[i] != ' ') printf("%c", name[i]);
    }
    printf(" or ");

    // keeping spaces, printing backwards
    for (i = strlen(name); i >= 0; i--) {
      printf("%c", name[i]);
    }
     printf("\n");

    // converting keyword to alphabetic indexes
    // for shifting each message letter with the 
    // caesar cipher

    printf("Vigenare keyword is: ");
    for (i = 0; i < strlen(keyword); i++) {
      printf("%c ", keyword[i]);
    }
     printf("\n");

    printf("Vigenare shifts are: ");
    for (i = 0; i < strlen(keyword); i++) {
      char *pos = strchr (alphabet, keyword[i]);
      int position = pos ? pos - alphabet : -1;
      printf("%d ", position);
    }
     printf("\n");

  printf("\nThe cypher challenge text is :\n");
  for (i = 0; i < strlen(cyphertext); i++){
    if (i%30 == 0) printf("\n");
    printf("%c", cyphertext[i]);
  }

    printf("\n\n");
    printf("[We think we know: \"WKH\" is \"the\"]\n");
    printf("[We are trying . : \"D\" as \"a\" and \"V\" as \"s\"]\n");

    printf("\nAaand, translated the text is :\n");
    for (i=0; i<strlen(cyphertext); i++){
      // formatting
      //if (i%30 == 0) printf("\n");

      // translated letters
      if (cyphertext[i] == 'W') printf("t"); else
      if (cyphertext[i] == 'K') printf("h"); else
      if (cyphertext[i] == 'H') printf("e"); else

      // trying these ones
      if (cyphertext[i] == 'D') printf("a"); else
      if (cyphertext[i] == 'V') printf("s"); else

      // display the letter we don't know yet
      printf("%c", cyphertext[i]);
    }
    printf("\n");

    printf("\nAlphabet with a Caesar shift\n");
    for (i = 0; i < strlen(alphabet); i++) {
      printf("%c", alphabet[i]);
      printf(" -> %c, ",alphabet[((i + shift) % 26)]);
    }
    printf("\n");

    printf("\nAlphabet with an affine shift\n");
    for (i = 0; i < strlen(alphabet); i++) {
      printf("%c", alphabet[i]);
      printf(" -> %c, ",alphabet[((a*i + b) % 26)]);
    }
    printf("\n");

    printf("\nAlphabet with keyword shift\n");
    int j = 0;
    for (i = 0; i < strlen(alphabet); i++) {
      printf("%c", alphabet[i]);
      char *pos = strchr (alphabet, keyword[ j++ ]);
      int shift = pos ? pos - alphabet : -1;
      printf(" -> %c, ",alphabet[((i + shift) % 26)]);
      if (j == strlen(keyword)) j = 0;
    }
    printf("\n");
    return 0;
} 

