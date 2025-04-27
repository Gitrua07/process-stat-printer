#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_output_pid(int pid, char *pid_name, char *file_name, int threads, int total_cont_switches)
{
   /*
    *get_voluntary_cont_switches - Outputs information about the user specified pid
    *
    * Parameters:
    * reqs - a pointer to an array of chars which hold a string that is meant to be found in filepid
    * filepid - a pointer to an opened file
    * header - a pointer to an array of chars which holds strings of filepid
    * total_cont_switches - an integer of the number of voluntary context switches
    *
    */

   printf("Process number: %d\n", pid);
   printf("Name: %s\n", pid_name);
   printf("Filename (if any): %s\n", file_name);
   printf("Threads: %d\n", threads);
   printf("Total context switches: %d\n", total_cont_switches);
}

int get_nonvol_cont_switches(char *reqs, FILE *filepid, char *header, int nonvol_cont_switches)
{
   /*
    *get_voluntary_cont_switches - Finds the pid's non-voluntary context switches
    *
    * Parameters:
    * reqs - a pointer to an array of chars which hold a string that is meant to be found in filepid
    * filepid - a pointer to an opened file
    * header - a pointer to an array of chars which holds strings of filepid
    * nonvol_cont_switches - an integer of the number of non-voluntary context switches
    *
    * Returns - an integer of the number of non-voluntary context switches
    *
    */

   while (!feof(filepid))
   {
      if(fscanf(filepid, "%s", header)==-1){
         break;
      }

      if (strcmp(header, reqs) == 0)
      {
         fscanf(filepid, "%d", &nonvol_cont_switches);
         break;
      }
   }

   return nonvol_cont_switches;
}

int get_voluntary_cont_switches(char *reqs, FILE *filepid, char *header, int voluntary_cont_switches)
{
   /*
    * get_voluntary_cont_switches - Finds the pid's voluntary context switches
    *
    * Parameters:
    * reqs - a pointer to an array of chars which hold a string that is meant to be found in filepid
    * filepid - a pointer to an opened file
    * header - a pointer to an array of chars which holds strings of filepid
    * voluntary_cont_switches - an integer of the number of voluntary context switches
    *
    * Returns - an integer of the number of voluntary context switches
    */

   while (!feof(filepid))
   {
      if(fscanf(filepid, "%s", header)==-1){
         break;
      }

      if (strcmp(header, reqs) == 0)
      {
         fscanf(filepid, "%d", &voluntary_cont_switches);

         sprintf(reqs, "nonvoluntary_ctxt_switches:");
         break;
      }
   }

   return voluntary_cont_switches;
}

int get_threads(char *reqs, FILE *filepid, char *header, int threads)
{
   /*
    *get_threads - Finds the number of threads in the pid
    *
    * Parameters:
    * reqs - a pointer to an array of chars which hold a string that is meant to be found in filepid
    * filepid - a pointer to an opened file
    * header - a pointer to an array of chars which holds strings of filepid
    * threads - an integer of the number of threads
    *
    * Returns - an integer of the number of threads
    *
    */
   while (!feof(filepid))
   {
      if(fscanf(filepid, "%s", header)==-1){
         break;
      }

      if (strcmp(header, reqs) == 0)
      {
         fscanf(filepid, "%d", &threads);

         sprintf(reqs, "voluntary_ctxt_switches:");
         break;
      }
   }

   return threads;
}

void get_pid_name(char *reqs, FILE *filepid, char *header, char *pid_name)
{
   /*
    * get_pid_name - Finds the pid name
    *
    * Parameters:
    * reqs - a pointer to an array of chars which hold a string that is meant to be found in filepid
    * filepid - a pointer to an opened file
    * header - a pointer to an array of chars which holds strings of filepid
    * pid_name - a pointer to an array of chars that will store the pid name
    *
    */
   sprintf(reqs, "Name:");
   while (!feof(filepid))
   {
      if(fscanf(filepid, "%s", header)==-1){
         break;
      }

      if (strcmp(header, reqs) == 0)
      {
         fscanf(filepid, "%s", pid_name);

         sprintf(reqs, "Threads:");
         break;
      }
   }
}

FILE *open_file(int pid, char *file, char *addr, int is_pid)
{
   /*
    * open_file - Opens the file of /proc
    *
    * Parameters:
    * pid - contains an integer of the process number given by the user
    * file - will hold the file address that is meant to be opened and read
    * is_pid - 0 means no pid, 1 means there is a specified pid
    *
    * Returns - a file pointer of the open file
    *
    */

   if (is_pid == 1)
   {
      sprintf(file, addr, pid);
   }
   else
   {
      file = addr;
   }
   FILE *filepid = fopen(file, "r");

   return filepid;
}

void get_model_name(FILE *filepid, char *model_name, char *header, char *reqs)
{
   /**
    * get_model_name - finds the model name of the cpu
    *
    * filepid - a pointer to an opened file
    * model_name - a pointer to a string that will be the cpu model name
    * header - a pointer to an array of chars which holds strings of filepid
    * reqs - a pointer to an array of chars which hold a string that is meant to be found in filepid
    *
    */
   sprintf(reqs, "name");
   while (!feof(filepid))
   {
      fscanf(filepid, "%s", header);

      if (strcmp(header, reqs) == 0)
      {
         fscanf(filepid, "%s", model_name);
         fscanf(filepid, "%s", model_name);

         sprintf(reqs, "stepping");
         char *temp;
         while (strcmp(temp, reqs) != 0)
         {
            if(fscanf(filepid, "%s", header)==-1){
               break;
            }
            temp = header;

            if (strcmp(temp, reqs) == 0)
            {
               break;
            }

            strcat(model_name, " ");
            strcat(model_name, header);
         }

         break;
      }
   }
}

int get_num_cores(FILE *filepid, int num_cores, char *header, char *reqs)
{
   /**
    * get_num_cores - finds the number of cores
    *
    * filepid - a pointer to an opened file
    * num_cores - an integer that will contain the number of cores
    * header - a pointer to an array of chars which holds strings of filepid
    * reqs - a pointer to an array of chars which hold a string that is meant to be found in filepid
    *
    * Returns - the total number of cores
    *
    */

   sprintf(reqs, "cores");

   while (!feof(filepid))
   {
      if(fscanf(filepid, "%s", header)==-1){
         break;
      }
      if (strcmp(header, reqs) == 0)
      {
         fscanf(filepid, "%s", header);
         fscanf(filepid, "%d", &num_cores);
      }
   }
   return num_cores;
}

void get_vers_lin(FILE *filepid, char *lin_ver, char *header, char *reqs)
{
   /*Errors - Repeats 2025 twice*/

   /**
    * get_vers_lin - gets the linux version number
    *
    * filepid - a pointer to an opened file
    * lin_ver - a pointer to the linux version number
    * header - a pointer to an array of chars which holds strings of filepid
    * reqs - a pointer to an array of chars which hold a string that is meant to be found in filepid
    *
    */

   fscanf(filepid, "%s", lin_ver);

   while (!feof(filepid))
   {
      if(fscanf(filepid, "%s", header) == -1){
         break;
      }
      strcat(lin_ver, " ");
      strcat(lin_ver, header);
   }
}

void get_tot_mem(FILE *filepid, char *tot_mem, char *header, char *reqs)
{
   /**
    * get_tot_mem - gets the total memory in kilobytes
    *
    * filepid - a pointer to an opened file
    * tot_mem - a pointer to the total memory in kb
    * header - a pointer to an array of chars which holds strings of filepid
    * reqs - a pointer to an array of chars which hold a string that is meant to be found in filepid
    *
    */

   fscanf(filepid, "%s", tot_mem);
   fscanf(filepid, "%s", tot_mem);

   fscanf(filepid, "%s", header);

   strcat(tot_mem, " ");
   strcat(tot_mem, header);
}

void get_uptime(FILE *filepid, char *uptime, char *header, char *reqs)
{
   /**
    * get_uptime - gets the total uptime in days, hours, minutes and seconds
    *
    * filepid - a pointer to an opened file
    * uptime - a pointer to the total uptime
    * header - a pointer to an array of chars which holds strings of filepid
    * reqs - a pointer to an array of chars which hold a string that is meant to be found in filepid
    *
    */

   int t_uptime;
   fscanf(filepid, "%d", &t_uptime);

   int days = t_uptime / 86400; /* Line 312 - 315: Generated with ChatGPT */
   int hours = t_uptime / 3600 - (days * 24);
   int mins = t_uptime / 60 - (days * 1440) - (hours * 60);
   int seconds = t_uptime - (days * 86400) - (hours * 3600) - (mins * 60);

   sprintf(uptime, "%d days, %d hours, %d mins, %d seconds", days, hours, mins, seconds);
}

void print_output(char *model_name, int num_cores, char *lin_ver, char *tot_mem, char *uptime)
{
   /**
    * print_output - prints the output that contains no pid
    *
    * model_name: contains the model name of the cpu
    * num_cores: contains the number of cores
    * lin_var: contains the version of linux
    * tot_me: contains the total memory in kb
    * uptime: contains the uptime expressed in days, hours, minutes and seconds
    *
    */

   printf("model name: %s\n", model_name);

   printf("cpu cores: %d\n", num_cores);

   printf("%s\n", lin_ver);

   printf("MemTotal: %s\n", tot_mem);

   printf("Uptime: %s\n", uptime);
}

int main(int argc, char **argv)
{
   int pid;                        /* contains the process number */
   char header[1000];              /* contains the strings of filepid which is meant to be compared with reqs */
   char pid_name[1000];            /* contains the pid name */
   char file_name[1000];           /* contains the file name */
   int threads;                    /* threads contains the number of threads in the pid */
   int voluntary_cont_switches;    /* contains the number of voluntary context switches */
   int nonvol_cont_switches;       /* contains the number of non-voluntary context switches */
   int total_cont_switches;        /* contains the sum of both non-voluntary and voluntary context switches */
   char reqs[1000];                /* reqs holds all strings of data that needs to be found in file */
   char file[1000];                /* file contains the path of the /proc file */
   char *addr = "/proc/%d/status"; /* contains the file address */

   char model_name[1000]; /*contains the model name of the cpu*/
   int num_cores; /*contains the number of cores*/
   char lin_ver[1000]; /*contains the version of linux*/
   char tot_mem[1000];/*contains the total memory in kb*/
   char uptime[1000];/*contains the uptime expressed in days, hours, minutes and seconds*/
   
   FILE *filepid; /*contains the opened file*/

   if (argv[1] != NULL) /* pid is specified */
   {
      sscanf(argv[1], "%d", &pid); /* pid contains the user input */

      filepid = open_file(pid, file, addr, 1); /* filepid contains the opened file that is being read */
      if (filepid == NULL)
      {
         printf("Process number %d not found.\n", pid);
         return 0;
      }

      get_pid_name(reqs, filepid, header, pid_name);

      threads = get_threads(reqs, filepid, header, threads);

      voluntary_cont_switches = get_voluntary_cont_switches(reqs, filepid, header, voluntary_cont_switches);

      nonvol_cont_switches = get_nonvol_cont_switches(reqs, filepid, header, nonvol_cont_switches);

      total_cont_switches = voluntary_cont_switches + nonvol_cont_switches;

      fclose(filepid);

      addr = "/proc/%d/cmdline";

      filepid = open_file(pid, file, addr, 1); /*filepid now contains the opened file of the cmdline of pid inputted number*/
      if (filepid == NULL)
      {
         printf("Process number %d not found.\n", pid);
         return 0;
      }

      fscanf(filepid, "%s", file_name);

      fclose(filepid);

      print_output_pid(pid, pid_name, file_name, threads, total_cont_switches);
   }
   else /* pid is not specified */
   {
      addr = "/proc/cpuinfo";
      filepid = open_file(pid, file, addr, 0);
      if (filepid == NULL)
      {
         printf("File failed to open.\n");
         return 0;
      }

      get_model_name(filepid, model_name, header, reqs);

      num_cores = get_num_cores(filepid, num_cores, header, reqs);

      fclose(filepid);

      addr = "/proc/version";
      filepid = open_file(pid, file, addr, 0);
      if (filepid == NULL)
      {
         printf("File failed to open.\n");
         return 0;
      }

      get_vers_lin(filepid, lin_ver, header, reqs);

      fclose(filepid);

      addr = "/proc/meminfo";
      filepid = open_file(pid, file, addr, 0);
      if (filepid == NULL)
      {
         printf("File failed to open.\n");
         return 0;
      }

      get_tot_mem(filepid, tot_mem, header, reqs);

      fclose(filepid);

      addr = "/proc/uptime";
      filepid = open_file(pid, file, addr, 0);
      if (filepid == NULL)
      {
         printf("File failed to open.\n");
         return 0;
      }

      get_uptime(filepid, uptime, header, reqs);

      fclose(filepid);

      print_output(model_name, num_cores, lin_ver, tot_mem, uptime);
   }

   return 0;
}