/*
 *
 *
 * CS 441/541: CPU Scheduler
 */
#include "scheduler.h"

void fcfs(struct process p[numProc])
{
  printf("Running...\n");
  sleep(2);
  printf("##################################################\n"
  "#  #    CPU     Pri     W     T\n");

  wTime = (int*)malloc(numProc * sizeof(int));
  tTime = (int*)malloc(numProc * sizeof(int));

  int i;
  for(i = 0; i < numProc; i++)
  {
    if(i == 0)
    {
      wTime[i] = 0;
      tTime[i] = p[i].cpuBurst;
    }
    else
    {
      wTime[i] = tTime[i-1];
      tTime[i] = tTime[i-1] + p[i].cpuBurst;
    }
    printf("#  %d     %d       %d     %d     %d\n",
    p[i].procId, p[i].cpuBurst, p[i].prior, wTime[i], tTime[i]);
  }

  for(i = 0; i < numProc; i++)
  {
    totalT += tTime[i];
    totalW += wTime[i];
  }

  avgT = totalT / numProc;    //calculating average turnaround and
  avgW = totalW / numProc;    //waiting times

  printf("##################################################\n");
  printf("# Avg. Waiting Time   :  %.2f\n", avgW);
  printf("# Avg. Turnaround Time: %.2f\n", avgT);
  printf("##################################################\n");

  free(wTime);
  free(tTime);
}

void sjf(struct process p[numProc])
{
  struct process temp;

  int i;
  for(i = 0; i < numProc; i++)  //sorting processes by sjf
  {
    for(i = 0; i < numProc; i++)
      {
        if(p[i].cpuBurst > p[i+1].cpuBurst)
        {
          temp = p[i];
          p[i] = p[i+1];
          p[i+1] = temp;
        }
      }
    }

  printf("Running...\n");
  sleep(2);
  printf("##################################################\n"
  "#  #    CPU     Pri     W     T\n");

  wTime = (int*)malloc(numProc * sizeof(int));
  tTime = (int*)malloc(numProc * sizeof(int));

  for(i = 0; i < numProc; i++)
  {
    if(i == 0)
    {
      wTime[i] = 0;
      tTime[i] = p[i].cpuBurst;
    }
    else
    {
      wTime[i] = tTime[i-1];
      tTime[i] = tTime[i-1] + p[i].cpuBurst;
    }
    printf("#  %d     %d       %d     %d     %d\n",
    p[i].procId, p[i].cpuBurst, p[i].prior, wTime[i], tTime[i]);
  }

  for(i = 0; i < numProc; i++)
  {
    totalT += tTime[i];
    totalW += wTime[i];
  }

  avgT = totalT / numProc;    //calculating average turnaround and
  avgW = totalW / numProc;    //waiting times

  printf("##################################################\n");
  printf("# Avg. Waiting Time   :  %.2f\n", avgW);
  printf("# Avg. Turnaround Time: %.2f\n", avgT);
  printf("##################################################\n");

  free(wTime);
  free(tTime);
}

void priority(struct process p[numProc])
{
  struct process temp;

  int i;
  for(i = 0; i < numProc; i++)  //sorting processes by priority
  {
    for(i = 0; i < numProc; i++)
      {
        if(p[i].prior > p[i+1].prior)
        {
          temp = p[i];
          p[i] = p[i+1];
          p[i+1] = temp;
        }
      }
    }

  printf("Running...\n");
  sleep(2);
  printf("##################################################\n"
  "#  #    CPU     Pri     W     T\n");

  wTime = (int*)malloc(numProc * sizeof(int));
  tTime = (int*)malloc(numProc * sizeof(int));

  for(i = 0; i < numProc; i++)
  {
    if(i == 0)
    {
      wTime[i] = 0;
      tTime[i] = p[i].cpuBurst;
    }
    else
    {
      wTime[i] = tTime[i-1];
      tTime[i] = tTime[i-1] + p[i].cpuBurst;
    }
    printf("#  %d     %d       %d     %d     %d\n",
    p[i].procId, p[i].cpuBurst, p[i].prior, wTime[i], tTime[i]);
  }

  for(i = 0; i < numProc; i++)
  {
    totalT += tTime[i];
    totalW += wTime[i];
  }

  avgT = totalT / numProc;    //calculating average turnaround and
  avgW = totalW / numProc;    //waiting times

  printf("##################################################\n");
  printf("# Avg. Waiting Time   :  %.2f\n", avgW);
  printf("# Avg. Turnaround Time: %.2f\n", avgT);
  printf("##################################################\n");

  free(wTime);
  free(tTime);
}

void rr(int quan, struct process p[numProc])
{
  printf("Running...\n");
  sleep(2);
  printf("##################################################\n"
  "#  #    CPU     Pri     W     T\n");

  wTime = (int*)malloc(numProc * sizeof(int));
  tTime = (int*)malloc(numProc * sizeof(int));

  int i;
  for(i = 0; i < numProc; i++)
  {
    if(i == 0)
    {
      wTime[i] = (int)(p[i].cpuBurst / quan);
      tTime[i] = p[i].cpuBurst + wTime[i];
    }
    else
    {
      wTime[i] = (int)(p[i].cpuBurst / quan + wTime[i-1]);
      tTime[i] = p[i].cpuBurst + wTime[i];
    }
    printf("#  %d     %d       %d     %d     %d\n",
    p[i].procId, p[i].cpuBurst, p[i].prior, wTime[i], tTime[i]);
  }

  for(i = 0; i < numProc; i++)
  {
    totalT += tTime[i];
    totalW += wTime[i];
  }

  avgT = totalT / numProc;      //calculating average turnaround and
  avgW = totalW / numProc;      //waiting times

  printf("##################################################\n");
  printf("# Avg. Waiting Time   :  %.2f\n", avgW);
  printf("# Avg. Turnaround Time: %.2f\n", avgT);
  printf("##################################################\n");

  free(wTime);
  free(tTime);
}

int main(int argc, char **argv)
{
  char line[LINELEN];
  char filename[LINELEN];
  FILE * fpointer;

  int i;
  for(i = 1; i < argc; i++)
  {
    if(strcmp(argv[i], "-s") == 0)
    {
      num = atoi(argv[i+1]);
    }

    if(strcmp(argv[i], "-q") == 0)
    {
      quan = atoi(argv[i+1]);
    }

    if(strstr(argv[i], ".txt") != NULL)
    {
      if(check == 0)
      {
        strcpy(filename, argv[i]);
        check = 1;
      }
    }
  }

  if(num < 1 || num > 4)
  {
    printf("Please give input for -s parameter.\n");
    printf("options: 1-4\n");
    exit(0);
  }

  if(num == 4 && quan < 1)
  {
    printf("Please give input for -q paramter.\n");
    exit(0);
  }

  fpointer = fopen(filename, "r");

  if(fpointer == NULL)
  {
    printf("cannot open file \n");
    exit(0);
  }

  fgets(line, LINELEN, fpointer);
  numProc = atoi(line);   //convert char num to int

  struct process p[numProc];

  for(i = 0; i < numProc; i++)
  {
    fgets(line, LINELEN, fpointer);
    sscanf(line, "%d %d %d", &p[i].procId, &p[i].cpuBurst, &p[i].prior);
  }

  if(num == 1)
  {
    strncpy(alg, "FCFS", 8);
    quan = 0;
  }
  if(num == 2)
  {
    strncpy(alg, "SJF", 8);
    quan = 0;
  }
  if(num == 3)
  {
    strncpy(alg, "Priority", 8);
    quan = 0;
  }
  if(num == 4)
    strncpy(alg, "RR", 8);

  printf("Scheduler     :  %d %s\n"
       "Quantum       :  %d\n"
       "Sch. File     :  %s\n"
       "-------------------------------\n", num, alg, quan, filename);
  printf("Arrival Order :   ");
  for(i = 0; i < numProc - 1; i++)
  {
    printf("%d, ", p[i].procId);
  }
  printf("%d\n", p[numProc - 1].procId);
  printf("Process Information :\n");

  for(i = 0; i < numProc; i++)
  {
    printf("%d    %d    %d\n", p[i].procId, p[i].cpuBurst, p[i].prior);
  }

  printf("-------------------------------\n");

  fclose(fpointer);

  if(num == 1) fcfs(p);
  if(num == 2) sjf(p);
  if(num == 3) priority(p);
  if(num == 4) rr(quan, p);

  return 0;
}
