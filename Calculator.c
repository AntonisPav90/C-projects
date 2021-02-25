#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int add(int a, int b)   /*συνάρτηση πρόσθεσης*/
{
    return(a+b);   /*επιστρέφει το άθροισμα*/
}

int sub(int a, int b)   /*συνάρτηση αφαίρεσης*/
{
    return(a-b);   /*επιστρέφει τη διαφορά*/
}

int mul(int a, int b)   /*συνάρτηση πολλαπλασιασμού*/
{
    return(a*b);   /*επιστρέφει το γινόμενο*/
}

double divide(int a, int b)     /*συνάρτηση διαίρεσης*/
{
while (b==0)    /*ελέγχει εάν ο παρονομαστής είναι μηδέν(0). όσο ο χρήστης δίνει μηδέν  		       στον παρονομαστή, ξαναζητάει ακέραιο αριθμό με εξαίρεση το  			       μηδέν(0).*/
        {
                      printf("You gave a zero denominator. Please give ");
                     printf(" a non zero integer value:"); 
                     scanf("%d",&b);        
       }
    return (  ((double)a) / b );   /*επιστρέφει το πηλίκο*/
}


int greater(int a, int b)       /*συνάρτηση μεγαλύτερου*/
{
if (a>b)        /*αν το a είναι μεγαλύτερο του b τότε επιστρέφει το a, αλλιώς επιστρέφει το 	               b.*/
              return a;
     else
              return b;       
       
}

int less(int a, int b)          /*συνάρτη μικρότερου*/
{
      if (a<b)    /*αν το a είναι μικρότερο του b τότε επιστρέφει το a, αλλιώς επιστρέφει το b.*/
            return a;
     else
            return b;       
       
}





int main()   /*η συνάρτηση main ξεκινά την εκτέλεση του προγράμματος*/
{
       char c;       /*δηλώνουμε τον χαρακτήρα c για την επιλογή τελεστή*/
       int a,b;      /*δηλώνουμε τους ακεραίους a και b που δίνει αργότερα ο χρήστης*/
      double ap;    /*δηλώνουμε το αποτέλεσμα που είναι τύπου double λόγω της διαίρεσης*/
  
  
  
    do
    {
      
           printf("Please enter one of the following:\n For Add press '+'\n ");
           printf( "For Sub press '-'\n For Mul press '*'\n For Div press '/'\n ");
           printf( "For Greater press '>'\n For Less press '<'\n");
           printf( " For Power press '^'\n ");
           printf( "For Exit press 'e'\n");
           scanf(" %c",&c);      /*ο χρήστης δίνει τον τελεστή*/
           if(  ( (c=='+') || (c=='-') || (c=='*') || (c=='/') || (c=='^')
              || (c=='<') || (c=='>') )    &&    (c!='e')    )      /*ελέγχει αν ο χρήστης έδωσε σωστό 						      τελεστή και όχι e*/
           {
                 printf("Give first integer:\n");        /*ο χρήστης δίνει τους 2 ακεραίους*/
                 scanf("%d",&a);
                 printf("Give second integer:\n");
                 scanf("%d",&b);
  
                 switch (c)      /*επιλέγει τον χαρακτήρα c που περιέχει τον τελεστή που			                        έδωσε ο χρήστης*/
                  {
                                       case '+':    ap=add(a,b);        /*αν ο τελεστής είναι + καλεί την 							   συνάρτηση πρόσθεσης*/
                                      break;    
         
                                     case '-':    ap=sub(a,b);        /*αν ο τελεστής είναι - καλεί την συνάρτηση 					              αφαίρεσης*/
                                     break;
         
                                    case '*':    ap=mul(a,b);        /*αν ο τελεστής είναι * καλεί την συνάρτηση 					              πολλαπλασιασμού*/
                                    break;
         
                                    case '/':    ap=divide(a,b);     /*αν ο τελεστής είναι / καλεί την συνάρτηση 						διαίρεσης*/
                                   break;
         
                                   case '>':    ap=greater(a,b);    /*αν ο τελεστής είναι > καλεί την 							συνάρτηση μεγαλύτερου*/
                                  break;
         
                                  case '<':    ap=less(a,b);       /*αν ο τελεστής είναι < καλεί την συνάρτηση 					             μικρότερου*/
                                 break;
         
                                case '^':    ap=pow(a,b);        /*αν ο τελεστής είναι ^ καλεί την συνάρτηση 						δύναμης η οποία δίδεται έτοιμη από την 						βιβλιοθήκη math.h που έγινε include στην 						αρχή.*/
                               break;
                   }       /*τέλος του switch*/
                  printf("The result is: %g \n\n\n",ap); /*εμφάνιση αποτελέσματος*/
                
        }    /*τέλος του if*/
       else
            if(c!='e')   /*αν ο χαρακτήρας που έδωσε οχρήστης δεν είναι κάποιος τελεστής αλλά 		 ούτε και το e τότε του εμφανίζει αυτό το μήνυμα.*/
           {
                printf("You gave a wrong character!\n\n");
           }
      
    }while (c!='e');    /*όλη η παραπάνω διαδικασία συνεχίζεται μέχρι ο χρήστης να δώσει τον 		     χαρακτήρα c.*/

    printf("\nThe program terminated successfully!\n");      /*αν ο χρήστης δώσει τον 								 χαρακτήρα e το πρόγραμμα								 τερματίζεται και εμφανίζεται αυτό 							 το μήνυμα.*/
	
   return 0;        /*δείχνει ότι το πρόγραμμα ολοκληρώθηκε με επιτυχία*/
}       /*τέλος της main*/
