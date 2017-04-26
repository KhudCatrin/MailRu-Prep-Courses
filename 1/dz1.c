#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Написать программу, которая в качестве аргументов командной строки
 * принимает заданное слово (первый аргумент) и имена текстовых файлов (документов). 
 * Необходимо для этого слова посчитать среднее арифметическое его вхождений в документы: 
 * Слова во входных файлах разделяются символами, 
 * для которых библиотечные функции isspace() или ispunct() возвращают ненулевое значение.
 */

int main(int argc, const char * argv[])
 {
    char sprt[]=", . ! ? < > /| ()* : ;' '";
    const int len = 128;
    char line[len];
    int doc_num = argc-2;
    int frq[doc_num];
  
    if (argc ==1 )
    {
      printf("Введите слово и хотя бы один файл!\n");
      exit(EXIT_FAILURE);
    }
    if (argc == 2)
    {
      printf("Введите путь хотя бы для одного файла\n");
      exit(EXIT_FAILURE); 
    }

    
    for (int i = 2, j = 0; i < argc; ++i, ++j)
    {
      docs[j] = fopen (argv[i] , "r+t");
      if (docs[j] == NULL)
      {
        perror ("Can't open file");
        exit(EXIT_FAILURE);
      }
    }
    
    FILE *docs[doc_num];
    int word_counter = 0;
    for (int i = 0; i<doc_num; ++i)
    {
        while (fgets(line, len, docs[i])!=NULL)
        {
           char *token = strtok(line, sprt);
           while (token!=NULL)
           {
              if (!strcmp(token, argv[1]))
              ++word_counter;
              token = strtok(NULL,sprt);
            }
         }
      frq[i] = word_counter;
      word_counter=0;
    }

    int s = 0;
    for (int i = 0; i<doc_num; ++i)
      s+=frq[i];
      
    float mid =(float)s/(float)doc_num;

    for (int i = 0; i < doc_num; ++i)
        fclose(docs[i]);
      
    printf("%.2f",mid);
    return 0;
}
