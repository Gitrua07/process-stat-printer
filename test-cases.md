# Additional Test Cases for A2

It is recommended that you use the small test case found in the
assignment specification until success. The test cases provided 
here may run significantly longer than desired -- or even than your
code will be tested on.

Nevertheless, here are is a summary of input-output combinations to
support development.

## Table of Content:

- [Small Test Case](#Small-Test)
    - [Small Input](#inputtxt)
    - [Small Output](#outputtxt) 

- [Medium Test Case](#Medium-Test)
    - [Medium Input](#inputtxt-1) 
    - [Medium Output](#outputtxt-1)

- [Medium-Large Test Case](#Medium-Large-Test)
    - [Medium-Large Input](#inputtxt-2) 
    - [Medium-Large Output](#outputtxt-2) 

## Small-Test

- [Small Input](#inputtxt)
- [Small Output](#outputtxt) 

### input.txt:

```
e 10 6
W 6 7
E 3 10
```

### output.txt:

```
00:00:00.3 Train  2 is ready to go East
00:00:00.3 Train  2 is ON the main track going East
00:00:00.6 Train  1 is ready to go West
00:00:01.0 Train  0 is ready to go East
00:00:01.3 Train  2 is OFF the main track after going East
00:00:01.3 Train  1 is ON the main track going West
00:00:02.0 Train  1 is OFF the main track after going West
00:00:02.0 Train  0 is ON the main track going East
00:00:02.6 Train  0 is OFF the main track after going East
```

## Medium-Test

- [Medium Input](#inputtxt-1) 
- [Medium Output](#outputtxt-1)

### input.txt:

```
E 58 73
w 40 4
W 34 41
E 76 9
W 84 29
e 77 57
w 13 22
E 60 35
E 39 15
W 98 23
```

### output.txt:

```
00:00:01.3 Train  6 is ready to go West
00:00:01.3 Train  6 is ON the main track going West
00:00:03.4 Train  2 is ready to go West
00:00:03.5 Train  6 is OFF the main track after going West
00:00:03.5 Train  2 is ON the main track going West
00:00:03.9 Train  8 is ready to go East
00:00:04.0 Train  1 is ready to go West
00:00:05.8 Train  0 is ready to go East
00:00:06.0 Train  7 is ready to go East
00:00:07.6 Train  3 is ready to go East
00:00:07.6 Train  2 is OFF the main track after going West
00:00:07.6 Train  8 is ON the main track going East
00:00:07.7 Train  5 is ready to go East
00:00:08.4 Train  4 is ready to go West
00:00:09.1 Train  8 is OFF the main track after going East
00:00:09.1 Train  4 is ON the main track going West
00:00:09.8 Train  9 is ready to go West
00:00:12.0 Train  4 is OFF the main track after going West
00:00:12.0 Train  0 is ON the main track going East
00:00:19.3 Train  0 is OFF the main track after going East
00:00:19.3 Train  9 is ON the main track going West
00:00:21.6 Train  9 is OFF the main track after going West
00:00:21.6 Train  7 is ON the main track going East
00:00:25.1 Train  7 is OFF the main track after going East
00:00:25.2 Train  3 is ON the main track going East
00:00:26.1 Train  3 is OFF the main track after going East
00:00:26.1 Train  1 is ON the main track going West
00:00:26.5 Train  1 is OFF the main track after going West
00:00:26.5 Train  5 is ON the main track going East
00:00:32.2 Train  5 is OFF the main track after going East
```

## Medium-Large-Test 

- [Medium-Large Input](#inputtxt-2) 
- [Medium-Large Output](#outputtxt-2) 

### input.txt:

```
E 33 36
W 21 89
w 83 10
w 3 60
w 70 33
e 10 63
E 1 41
e 32 74
W 74 0
E 97 16
e 70 53
W 68 32
w 22 31
W 42 43
W 11 49
W 15 49
W 47 58
W 88 27
w 24 83
W 27 14
W 97 0
w 49 31
E 82 76
E 17 8
e 1 9
W 27 42
w 45 98
E 32 39
W 50 97
E 22 10
e 78 6
e 60 10
E 86 19
W 86 68
W 26 0
w 83 93
w 15 74
W 1 50
E 17 26
W 9 76
w 2 95
w 89 37
w 20 20
e 87 11
E 88 93
w 66 91
w 56 45
E 13 47
W 88 18
e 10 79
w 58 94
W 31 58
E 88 98
e 94 33
e 49 16
w 38 27
W 37 26
w 24 69
E 46 91
w 71 78
E 44 94
e 91 96
W 28 56
W 55 83
W 61 64
W 33 41
e 91 89
e 99 64
w 31 42
w 94 54
w 87 51
E 50 22
W 36 88
E 32 6
W 76 35
w 9 20
W 38 62
w 7 57
W 86 84
W 18 74
W 93 54
E 13 19
E 97 54
e 2 90
e 74 29
w 45 40
```

### output.txt:

```
00:00:00.1 Train  6 is ready to go East
00:00:00.1 Train 24 is ready to go East
00:00:00.1 Train 37 is ready to go West
00:00:00.1 Train  6 is ON the main track going East
00:00:00.2 Train 40 is ready to go West
00:00:00.2 Train 83 is ready to go East
00:00:00.3 Train  3 is ready to go West
00:00:00.7 Train 77 is ready to go West
00:00:00.9 Train 39 is ready to go West
00:00:00.9 Train 75 is ready to go West
00:00:01.0 Train  5 is ready to go East
00:00:01.0 Train 49 is ready to go East
00:00:01.1 Train 14 is ready to go West
00:00:01.3 Train 47 is ready to go East
00:00:01.3 Train 81 is ready to go East
00:00:01.5 Train 15 is ready to go West
00:00:01.5 Train 36 is ready to go West
00:00:01.7 Train 23 is ready to go East
00:00:01.7 Train 38 is ready to go East
00:00:01.8 Train 79 is ready to go West
00:00:02.0 Train 42 is ready to go West
00:00:02.1 Train  1 is ready to go West
00:00:02.2 Train 12 is ready to go West
00:00:02.2 Train 29 is ready to go East
00:00:02.4 Train 18 is ready to go West
00:00:02.4 Train 57 is ready to go West
00:00:02.6 Train 34 is ready to go West
00:00:02.7 Train 19 is ready to go West
00:00:02.7 Train 25 is ready to go West
00:00:02.8 Train 62 is ready to go West
00:00:03.1 Train 51 is ready to go West
00:00:03.1 Train 68 is ready to go West
00:00:03.2 Train  7 is ready to go East
00:00:03.2 Train 27 is ready to go East
00:00:03.2 Train 73 is ready to go East
00:00:03.3 Train  0 is ready to go East
00:00:03.3 Train 65 is ready to go West
00:00:03.6 Train 72 is ready to go West
00:00:03.7 Train 56 is ready to go West
00:00:03.8 Train 55 is ready to go West
00:00:03.8 Train 76 is ready to go West
00:00:04.2 Train 13 is ready to go West
00:00:04.2 Train  6 is OFF the main track after going East
00:00:04.2 Train 37 is ON the main track going West
00:00:04.4 Train 60 is ready to go East
00:00:04.5 Train 26 is ready to go West
00:00:04.5 Train 85 is ready to go West
00:00:04.6 Train 58 is ready to go East
00:00:04.7 Train 16 is ready to go West
00:00:04.9 Train 21 is ready to go West
00:00:04.9 Train 54 is ready to go East
00:00:05.0 Train 28 is ready to go West
00:00:05.0 Train 71 is ready to go East
00:00:05.5 Train 63 is ready to go West
00:00:05.6 Train 46 is ready to go West
00:00:05.8 Train 50 is ready to go West
00:00:06.0 Train 31 is ready to go East
00:00:06.1 Train 64 is ready to go West
00:00:06.6 Train 45 is ready to go West
00:00:06.8 Train 11 is ready to go West
00:00:07.0 Train  4 is ready to go West
00:00:07.0 Train 10 is ready to go East
00:00:07.1 Train 59 is ready to go West
00:00:07.4 Train  8 is ready to go West
00:00:07.4 Train 84 is ready to go East
00:00:07.6 Train 74 is ready to go West
00:00:07.8 Train 30 is ready to go East
00:00:08.2 Train 22 is ready to go East
00:00:08.3 Train  2 is ready to go West
00:00:08.3 Train 35 is ready to go West
00:00:08.6 Train 32 is ready to go East
00:00:08.6 Train 33 is ready to go West
00:00:08.6 Train 78 is ready to go West
00:00:08.7 Train 43 is ready to go East
00:00:08.7 Train 70 is ready to go West
00:00:08.8 Train 17 is ready to go West
00:00:08.8 Train 44 is ready to go East
00:00:08.8 Train 48 is ready to go West
00:00:08.8 Train 52 is ready to go East
00:00:08.9 Train 41 is ready to go West
00:00:09.1 Train 61 is ready to go East
00:00:09.1 Train 66 is ready to go East
00:00:09.2 Train 37 is OFF the main track after going West
00:00:09.2 Train 47 is ON the main track going East
00:00:09.3 Train 80 is ready to go West
00:00:09.4 Train 53 is ready to go East
00:00:09.4 Train 69 is ready to go West
00:00:09.7 Train  9 is ready to go East
00:00:09.7 Train 20 is ready to go West
00:00:09.7 Train 82 is ready to go East
00:00:09.9 Train 67 is ready to go East
00:00:13.9 Train 47 is OFF the main track after going East
00:00:13.9 Train 39 is ON the main track going West
00:00:21.5 Train 39 is OFF the main track after going West
00:00:21.5 Train 81 is ON the main track going East
00:00:23.4 Train 81 is OFF the main track after going East
00:00:23.4 Train 14 is ON the main track going West
00:00:28.3 Train 14 is OFF the main track after going West
00:00:28.3 Train 23 is ON the main track going East
00:00:29.1 Train 23 is OFF the main track after going East
00:00:29.1 Train 15 is ON the main track going West
00:00:34.0 Train 15 is OFF the main track after going West
00:00:34.0 Train 38 is ON the main track going East
00:00:36.6 Train 38 is OFF the main track after going East
00:00:36.6 Train 79 is ON the main track going West
00:00:44.0 Train 79 is OFF the main track after going West
00:00:44.0 Train 29 is ON the main track going East
00:00:45.0 Train 29 is OFF the main track after going East
00:00:45.1 Train  1 is ON the main track going West
00:00:54.0 Train  1 is OFF the main track after going West
00:00:54.0 Train 27 is ON the main track going East
00:00:57.9 Train 27 is OFF the main track after going East
00:00:57.9 Train 34 is ON the main track going West
00:00:57.9 Train 34 is OFF the main track after going West
00:00:57.9 Train 73 is ON the main track going East
00:00:58.5 Train 73 is OFF the main track after going East
00:00:58.5 Train 19 is ON the main track going West
00:00:59.9 Train 19 is OFF the main track after going West
00:00:59.9 Train  0 is ON the main track going East
00:01:03.5 Train  0 is OFF the main track after going East
00:01:03.5 Train 25 is ON the main track going West
00:01:07.7 Train 25 is OFF the main track after going West
00:01:07.7 Train 60 is ON the main track going East
00:01:17.1 Train 60 is OFF the main track after going East
00:01:17.1 Train 62 is ON the main track going West
00:01:22.7 Train 62 is OFF the main track after going West
00:01:22.7 Train 58 is ON the main track going East
00:01:31.8 Train 58 is OFF the main track after going East
00:01:31.8 Train 51 is ON the main track going West
00:01:37.6 Train 51 is OFF the main track after going West
00:01:37.6 Train 71 is ON the main track going East
00:01:39.8 Train 71 is OFF the main track after going East
00:01:39.8 Train 65 is ON the main track going West
00:01:43.9 Train 65 is OFF the main track after going West
00:01:43.9 Train 22 is ON the main track going East
00:01:51.5 Train 22 is OFF the main track after going East
00:01:51.5 Train 72 is ON the main track going West
00:02:00.3 Train 72 is OFF the main track after going West
00:02:00.3 Train 32 is ON the main track going East
00:02:02.2 Train 32 is OFF the main track after going East
00:02:02.2 Train 56 is ON the main track going West
00:02:04.8 Train 56 is OFF the main track after going West
00:02:04.8 Train 44 is ON the main track going East
00:02:14.1 Train 44 is OFF the main track after going East
00:02:14.1 Train 76 is ON the main track going West
00:02:20.3 Train 76 is OFF the main track after going West
00:02:20.3 Train 52 is ON the main track going East
00:02:30.1 Train 52 is OFF the main track after going East
00:02:30.1 Train 13 is ON the main track going West
00:02:34.4 Train 13 is OFF the main track after going West
00:02:34.4 Train  9 is ON the main track going East
00:02:36.1 Train  9 is OFF the main track after going East
00:02:36.1 Train 16 is ON the main track going West
00:02:41.9 Train 16 is OFF the main track after going West
00:02:41.9 Train 82 is ON the main track going East
00:02:47.3 Train 82 is OFF the main track after going East
00:02:47.3 Train 28 is ON the main track going West
00:02:57.0 Train 28 is OFF the main track after going West
00:02:57.0 Train 63 is ON the main track going West
00:03:05.3 Train 63 is OFF the main track after going West
00:03:05.3 Train 24 is ON the main track going East
00:03:06.2 Train 24 is OFF the main track after going East
00:03:06.2 Train 64 is ON the main track going West
00:03:12.6 Train 64 is OFF the main track after going West
00:03:12.6 Train 11 is ON the main track going West
00:03:15.8 Train 11 is OFF the main track after going West
00:03:15.8 Train 83 is ON the main track going East
00:03:24.8 Train 83 is OFF the main track after going East
00:03:24.8 Train  8 is ON the main track going West
00:03:24.8 Train  8 is OFF the main track after going West
00:03:24.8 Train 74 is ON the main track going West
00:03:28.3 Train 74 is OFF the main track after going West
00:03:28.3 Train  5 is ON the main track going East
00:03:34.6 Train  5 is OFF the main track after going East
00:03:34.6 Train 33 is ON the main track going West
00:03:41.4 Train 33 is OFF the main track after going West
00:03:41.4 Train 78 is ON the main track going West
00:03:49.8 Train 78 is OFF the main track after going West
00:03:49.8 Train 49 is ON the main track going East
00:03:57.7 Train 49 is OFF the main track after going East
00:03:57.7 Train 17 is ON the main track going West
00:04:00.4 Train 17 is OFF the main track after going West
00:04:00.4 Train 48 is ON the main track going West
00:04:02.2 Train 48 is OFF the main track after going West
00:04:02.2 Train  7 is ON the main track going East
00:04:09.6 Train  7 is OFF the main track after going East
00:04:09.6 Train 80 is ON the main track going West
00:04:15.0 Train 80 is OFF the main track after going West
00:04:15.0 Train 20 is ON the main track going West
00:04:15.0 Train 20 is OFF the main track after going West
00:04:15.0 Train 54 is ON the main track going East
00:04:16.6 Train 54 is OFF the main track after going East
00:04:16.6 Train 40 is ON the main track going West
00:04:26.1 Train 40 is OFF the main track after going West
00:04:26.2 Train 31 is ON the main track going East
00:04:27.2 Train 31 is OFF the main track after going East
00:04:27.2 Train  3 is ON the main track going West
00:04:33.2 Train  3 is OFF the main track after going West
00:04:33.2 Train 10 is ON the main track going East
00:04:38.5 Train 10 is OFF the main track after going East
00:04:38.5 Train 77 is ON the main track going West
00:04:44.2 Train 77 is OFF the main track after going West
00:04:44.2 Train 84 is ON the main track going East
00:04:47.1 Train 84 is OFF the main track after going East
00:04:47.1 Train 75 is ON the main track going West
00:04:49.1 Train 75 is OFF the main track after going West
00:04:49.1 Train 30 is ON the main track going East
00:04:49.7 Train 30 is OFF the main track after going East
00:04:49.7 Train 36 is ON the main track going West
00:04:57.1 Train 36 is OFF the main track after going West
00:04:57.1 Train 43 is ON the main track going East
00:04:58.2 Train 43 is OFF the main track after going East
00:04:58.2 Train 42 is ON the main track going West
00:05:00.2 Train 42 is OFF the main track after going West
00:05:00.2 Train 61 is ON the main track going East
00:05:09.8 Train 61 is OFF the main track after going East
00:05:09.8 Train 12 is ON the main track going West
00:05:12.9 Train 12 is OFF the main track after going West
00:05:12.9 Train 66 is ON the main track going East
00:05:21.8 Train 66 is OFF the main track after going East
00:05:21.8 Train 18 is ON the main track going West
00:05:30.1 Train 18 is OFF the main track after going West
00:05:30.1 Train 53 is ON the main track going East
00:05:33.4 Train 53 is OFF the main track after going East
00:05:33.4 Train 57 is ON the main track going West
00:05:40.3 Train 57 is OFF the main track after going West
00:05:40.3 Train 67 is ON the main track going East
00:05:46.7 Train 67 is OFF the main track after going East
00:05:46.7 Train 68 is ON the main track going West
00:05:50.9 Train 68 is OFF the main track after going West
00:05:50.9 Train 55 is ON the main track going West
00:05:53.6 Train 55 is OFF the main track after going West
00:05:53.6 Train 26 is ON the main track going West
00:06:03.4 Train 26 is OFF the main track after going West
00:06:03.4 Train 85 is ON the main track going West
00:06:07.4 Train 85 is OFF the main track after going West
00:06:07.5 Train 21 is ON the main track going West
00:06:10.6 Train 21 is OFF the main track after going West
00:06:10.6 Train 46 is ON the main track going West
00:06:15.1 Train 46 is OFF the main track after going West
00:06:15.1 Train 50 is ON the main track going West
00:06:24.5 Train 50 is OFF the main track after going West
00:06:24.5 Train 45 is ON the main track going West
00:06:33.6 Train 45 is OFF the main track after going West
00:06:33.6 Train  4 is ON the main track going West
00:06:36.9 Train  4 is OFF the main track after going West
00:06:36.9 Train 59 is ON the main track going West
00:06:44.7 Train 59 is OFF the main track after going West
00:06:44.7 Train  2 is ON the main track going West
00:06:45.7 Train  2 is OFF the main track after going West
00:06:45.7 Train 35 is ON the main track going West
00:06:55.0 Train 35 is OFF the main track after going West
00:06:55.0 Train 70 is ON the main track going West
00:07:00.1 Train 70 is OFF the main track after going West
00:07:00.1 Train 41 is ON the main track going West
00:07:03.8 Train 41 is OFF the main track after going West
00:07:03.8 Train 69 is ON the main track going West
00:07:09.2 Train 69 is OFF the main track after going West
```