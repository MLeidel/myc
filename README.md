# myc.h, mydb.h, mynet.h

<a name="top"></a>
## my\_.h functions

**[ String functions (_myc.h_) ](#mycstring)**
>
[charat](#charat) &bull; [chomp](#chomp) &bull; [cary_del](#cary_del) &bull; [cary_diaplay](#cary_diaplay)  
[cary_new](#cary_new) &bull; [cary_parse](#cary_parse) &bull; [concat](#concat) &bull; [contains](#contains)  
[cstr_new](#cstr_new) &bull; [cstr_cpy](#cstr_cpy) &bull; [cstr_del](#cstr_del)  
[deletechar](#deletechar) &bull; [endswith](#endswith) &bull; [equals](#equals) &bull; [equalsignor](#equalsignor)  
[field](#field) &bull; [indexof](#indexof) &bull; [insert](#insert) &bull; [lastcharat](#lastcharat) &bull; [lastindexof](#lastindexof)  
[leftof](#leftof) &bull; [lowercase](#lowercase) &bull; [ltrim](#ltrim) &bull; [replace](#replace) &bull; [replacesz](#replacesz)  
[rightof](#rightof) &bull; [rtrim](#rtrim) &bull; [startswith](#startswith) &bull; [strrev](#strrev)  
[strrstr](#strrstr) &bull; [strtype](#strtype) &bull; [substr](#substr) &bull; [trim](#trim)  
[uppercase](#uppercase) &bull; [urlencode](#urlencode)  

**[ File & Path functions (_myc.h_) ](#mycfile)**
>
[cary_dir](#cary_dir) &bull; [file_exists](#file_exists) &bull; [filesize](#filesize) &bull; [isfile](#isfile)  
[getbasename](#getbasename) &bull; [getbasepath](#getbasepath) &bull; [getfullpath](#getfullpath)  
[open_for_append](#open_for_append) &bull; [open_for_read](#open_for_read) &bull; [open_for_write](#open_for_write)  
[readfile](#readfile) &bull; [writefile](#writefile)

**[ Utility & Miscellaneous (_myc.h_) ](#mycother)**
>
[ARRSIZE](#ARRSIZE) &bull; 
[date](#date) &bull; [timeout](#timeout) &bull; [multifree](#multifree) &bull; [ERRMSG](#ERRMSG)  
[isort](#isort) &bull; [dsort](#dsort) &bull; [ssort](#ssort)  

**[ Database Sqlite3 functions _mydb.h_ ](#mydb)**
>
[mydb_count](#mydb_count) &bull; [mydb_names](#mydb_names) &bull; [mydb_open](#mydb_open)

**[ Net/Web functions _mynet.h_ ](#mynet)**
>
[webbrowser](#webbrowser) &bull; [webget](#webget) &bull; [webpage](#webpage) &bull; [webpost](#webpost)

---

# string.h

The standard C string.h library has fifteen or so functions for string
manipulation.

This section is a quick reference for the standard _string.h_ library.

## The Standard _string.h_ library for C

### memcpy(s,ct,n)
copy n chars from ct to s (may overlap) 

### memmove(s,ct,n)
copy n chars from ct to s (may overlap) 

### memcmp(cs,ct,n)
compare n chars of cs with ct

### memchr(cs,c,n)
pointer to first c in first n chars of cs

### memset(s,c,n)
put c into first n chars of s

### char \*strcpy( char \*s1, const char \*s2 )

copies the string s2 into the character array s1. The value of s1 is returned.

### char \*strncpy( char \*s1, const char \*s2, size_t n )

copies at most n characters of the string s2 into the character array s1. The value of s1 is
returned.

### char \*strcat( char \*s1, const char \*s2 )

appends the string s2 to the end of character array s1. The first character from s2
overwrites the '\0' of s1. The value of s1 is returned.

### char \*strncat( char \*s1, const char \*s2, size_t n )

appends at most n characters of the string s2 to the end of character array s1. The first
character from s2 overwrites the '\0' of s1. The value of s1 is returned.

### char \*strchr( const char \*s, int c )

returns a pointer to the first instance of c in s. Returns a NULL pointer if c is not
encountered in the string.

### char \*strrchr( const char \*s, int c )

returns a pointer to the last instance of c in s. Returns a NULL pointer if c is not
encountered in the string.

### char \*strdup(const char \*string)

returns a pointer to a duplicated string allocating
memory in the heap. Use free() to free memory.

### int strcmp( const char \*s1, const char \*s2 )

compares the string s1 to the string s2. The function returns 0 if they are the same, a
number < 0 if s1 < s2, a number > 0 if s1 > s2.

### int strncmp( const char \*s1, const char \*s2, size_t n )

compares up to n characters of the string s1 to the string s2. The function returns 0 if
they are the same, a number < 0 ifs1 < s2, a number > 0 if s1 > s2.

### size_t strspn( char \*s1, const char \*s2 )

returns the length of the longest substring of s1 that begins at the start of s1 and consists
only of the characters found in s2.
size_t strcspn( char \*s1, const char \*s2 )
returns the length of the longest substring of s1 that begins at the start of s1 and contains
none of the characters found in s2.

### size_t strlen( const char \*s )

determines the length of the string s. Returns the number of characters in the string
before the '\0'.

### char \*strpbrk( const char \*s1, const char \*s2 )

returns a pointer to the first instance in s1 of any character found in s2. Returns a NULL
pointer if no characters from s2 are encountered in s1.

### char \*strstr( const char \*s1, const char \*s2 )

returns a pointer to the first instance of string s2 in s1. Returns a NULL pointer if s2 is
not encountered in s1.

### char \*strtok(char \*s1, const char \*s2 )

repeated calls to this function modifies string s1 by breaking it into "tokens"--that is the
string is broken into substrings, each terminating with a '\0', where the '\0' replaces any
characters contained in string s2. The first call uses the string to be tokenized as s1;
subsequent calls use NULL as the first argument. A pointer to the beginning of the
current token is returned; NULL is returned if there are no more tokens.
consider using _cary..._ in myc.h.  
_Warning: this changes the original string!_

---------------------------------------------------------------------------------------

<a name="mycstring"></a>
## STRING functions _myc.h_ [^](#top 'top')

**_I've tried not to duplicate the existing string.h functions.  
The goal here is to extend (and simplify) string manipulation in C._**

>>...........................................................

<a name="charat"></a>
### int charat(char \*str, char c)
>Finds and returns the index of a character.
On failure returns -1.

<a name="chomp"></a>
### char \*chomp(char \*str)
>Removes record separators from the end of a string.

<a name="concat"></a>
### char \*concat(char \*dest, int num, ...)
>Concatenate a variable number of strings.

```c
    char s[MAX_L];

    strcpy(s, "Ms ");

    concat(s, 3, "Mary ", "Elizabeth ", "Smith");

    puts(s); // Ms Mary Elizabeth Smith
```

<a name="contains"></a>
### int contains(char \*str, char \*subs)
>Returns a count of the number of substrings found.  
Returns 0 if none found.

<a name="cstr_new"></a>
### cstr cstr_new(size_t length, char fill)
>Returns a pointer to a new string allocated  
to size _length_ and initialized with  
all _fill_ character. Uses the _cstr_ struct.

```c
    typedef struct {
        size_t length;  // allocated length
        char *str;
    } cstr;
```

<a name="cstr_cpy"></a>
### bool cstr_cpy(cstr s, char *data)
>Copies a string into a cstr string with  
boundary checking.

```c
    cstr my = cstr_new(255, '\0');
    cstr_cpy(my, "Hello World");
    puts(my.str);
    cstr_del(my);
```

<a name="cstr_del"></a>
### void cstr_del(cstr s)
>Frees memory for a string allocated  
with cstr_new.

<a name="deletechar"></a>
### char \*deletechar(char\* out, char\* in, char target, int number)
>Removes characters from a string.  
Limit replacements or 0 means all.

<a name="endswith"></a>
### bool endswith (char\* str, char\* subs)
>Returns true if string ends with specified substring,
otherwise returns false.

<a name="equals"></a>
### bool equals(char \*str1, char \*str2)
>Returns true if strings are equal,
otherwise returns false.

<a name="equalsignor"></a>
### bool equalsignor(char \*str1, char \*str2)
>Returns true if strings are equal
reguardless of any case differences,
otherwise returns false.

<a name="field"></a>
### char \*field(char \*fld, char \*str, char delimiter, int column, bool strip)
>Returns a substring at column n within a delimited string.
When _delimiter_ is a ' ' consecutive spaces they act as a single
delimiter. When _strip_ is _true_ leading and trailing
whitespace is removed. Delimiters are ignored inside of
double quotes. Double quotes are NOT REMOVED in the result.
See _deletechar_ function to remove quote characters.
The original string is preserved. Returns NULL if
_column_ is out of bounds.

<a name="indexof"></a>
### int indexof (char\* base, char\* str)
>Returns the index of a substring within a string.  
If not found returns -1.

<a name="insert"></a>
### char \*insert(char \*buf, char \*s, char \*ins, size_t index)
>Inserts a substring into a string at index.  
Returns the modified string.

```c
    char text[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit";
    char buf[120];

    insert(buf, text, " amor", 26);
    puts(buf);  //Lorem ipsum dolor sit amet amor, consectetur adipiscing elit

    puts(insert(buf, text, "\n", 28));
        // Lorem ipsum dolor sit amet,
       //  consectetur adipiscing elit

    puts(insert(buf, text, "prepended ", 0));
        // prepended Lorem ipsum dolor sit amet, consectetur adipiscing elit

    puts(insert(buf, text, " appended.", strlen(text))); //
        // Lorem ipsum dolor sit amet, consectetur adipiscing elit appended.

```

<a name="lastcharat"></a>
### int lastcharat(char* base, char c)
>Returns the __last__ index of "c" found
in "base". On failure returns -1.

<a name="lastindexof"></a>
### int lastindexof (char\* base, char\* str)
>Returns the __last__ index of a substring within
a string. If not found returns -1.

<a name="leftof"></a>
### char \*leftof (char \*out, char \*in, char \*targ, int start)
>Returns a pointer to a substring to the left of
some delimiting string.  
A starting offet may be used or set to 0.

<a name="lowercase"></a>
### char \*lowercase (char \*str)
>Returns the string in lower case.

<a name="ltrim"></a>
### char \*ltrim (char \*str)
>Returns the string with trailing whitespace
removed.

<a name="replace"></a>
### char \*replace (char \*out, char \*in, char \*target, char \*replacement, int number)
>Replaces substrings within a string. Limit replacements or
set to 0.

<a name="replacechar"></a>
### int replacechar (char \*in, char target, char replacement, int number)
>Replaces characters within a string. Limit replacements or
set to 0.  
Returns count of replacements made.

<a name="replacesz"></a>
### int replacesz(char \*in, char \*target, char \*replacement, int number)
>Returns a calculated new string length for a more accurate
memory allocation size when creating an output buffer for replace.

<a name="rightof"></a>
### char \*rightof (char \*out, char \*in, char \*delim, int start)
>Returns a pointer to a substring to the right of
some delimiting string.  
Set a starting index or 
set to 0.

<a name="rtrim"></a>
### char \*rtrim (char \*str)
>Returns string with trailing whitespace
removed.

<a name="startswith"></a>
### bool startswith (char\* str, char\* subs)
>Returns true if a string starts with some substring,
otherwise returns false.

<a name="strrev"></a>
### char \*strrev (char \*str)
>Returns a string with the character
sequence reversed.

<a name="strrstr"></a>
### char \*strrstr (char \*str, char \*subs)
>Returns a pointer to the last occurrence
of some substring within a string. Returns NULL if
not found. _Versions of string.h
may or may not have this function._

<a name="strtype"></a>
### int strtype (char \*buf, int istype)
>functions to detect the type of a string.   
Compliments ctype.h functions for characters:  
```
isalpha => strtype(buf, ALPHA)  
isalnum => strtype(buf, ALNUM)  
isdigit => strtype(buf, DIGIT)  
isprint => strtype(buf, PRINT)  
isspace => strtype(buf, SPACE)  
isupper => strtype(buf, UPPER)  
islower => strtype(buf, LOWER)  
ispunct => strtype(buf, PUNCT)  
Returns int:  
-  0 = none found  
-  N = number found  
- -1 = all found  
```
ALPHA .. PUNCT is an enum in that order.

<a name="substr"></a>
### char \*substr (char \*out, char \*in, int position, int length)
>Returns a substring within a string located by a start
position and a length.  
Checks boundaries for overflow.

<a name="trim"></a>
### char \*trim (char \*str)
>Returns the string with both leading and
trailing whitespace removed.

<a name="uppercase"></a>
### char \*uppercase (char \*str)
>Returns the string in all upper case.

<a name="urlencode"></a>
### char \*urlencode (char \*buf, char \*str)
>Returns the string with all characters
conforming to Uniform Resource Locator
syntax rules.

<a name="cary_new"></a>
## Parsing to an array _myc.h_ [^](#top 'top')

```c
  // struct used for cary functions
  typedef struct cary {
    int nbr_rows;  // maximum rows (columns, fields)
    int len_rows; // maximum length of one row (col, field)
    char ** get; // array of strings (fields)
  } cary;
```

### cary cary_new (int _nbr\_rows_, int _len\_rows_)
>Returns a *cary* structure pointer with memory
allocated to hold an array of strings (fields).  

```c
  cary a = cary_new(20, 65);
```
<a name="cary_parse"></a>
### int cary\_parse (cary \*a, char \*str, char \*delim)
>Splits a delimited string into an array of strings (fields.)  
Returns _int_ of actual number parsed.  
_cary\_init_ must used prior to this function.

```c
  cary a = cary_new(20, 65);
  int n = cary_parse(a, line, ",");
```
>Individual fields can now be accessed like:

```c
  a.get[n]  // where n is the row (field) number
```

>Delimiters are ignored inside double quotes.
Double quotes are NOT REMOVED from the result fields.
See _delchar_ function for removing quote characters.
When delimiter is " " (space) consecutive spaces
are treated as one delimiter. The input string is distroyed 
in the process.

<a name="cary_del"></a>
### void cary\_del(cary a)
>Frees memory allocated by
cary_new function.

```c
  cary_del(a);
```

<a name="cary_diaplay"></a>
### void cary\_diaplay (cary a)
>Prints out column numbers and values
to the console.

------------------------------------------------------------------------------------------------------

<a name="mycfile"></a>
## FILE & PATH functions _myc.h_ [^](#top 'top')

<a name="file_exists"></a>
### bool file\_exists (char \*filename)
>Return true if _filename_ exists
otherwise, returns false.

<a name="filesize"></a>
### long filesize(const char \*filename)
>Returns the byte size of a file.

<a name="isfile"></a>
### int isfile(const char* name)
>Return 1 if _name_ is a file.
Returns 0 if _name_ is a directory.
Returns -1 if _name_ is undetermined.

<a name="getbasename"></a>
### char \*getbasename(char \*fn, bool withext)
>Returns the basename of a file with or without  
the file extension.

<a name="getbasepath"></a>
### char \*getbasepath(char \*fn, char \*buff)
>Returns only the fullpath of a file  
**without the file name** itself.  
_see getfullpath_

<a name="getfullpath"></a>
### char \*getfullpath(char \*fn, char \*buff)
>Returns the fullpath of a file.  
_see getbasepath_

<a name="open_for_append"></a>
### FILE \* open_for_append (char \*fname)
>Returns a FILE handle to _fname_ or
NULL if unsuccessful.

<a name="open_for_read"></a>
### FILE \* open_for_read (char \*fname)
>Returns a FILE handle to _fname_ or
NULL if unsuccessful.

<a name="open_for_write"></a>
### FILE \* open_for_write (char \*fname)
>Returns a FILE handle to _fname_ or
NULL if unsuccessful.

<a name="readfile"></a>
### int readfile (char \*buffer, const char \*filename)
>Loads _buffer_ with the contents of _filename_ or
returns -1 if unsuccessful.

<a name="writefile"></a>
### int writefile (char \*buffer, const char \*filename, bool append)
>Writes _buffer_ to the contents of _filename_ or
returns -1 if unsuccessful.  
Appends to file if _append_ is true.

<a name="cary_dir"></a>
### cary cary_dir(const char *path, int dtype, bool sort)
>Returns a cary struct filled with file and/or directory
names for _path_. If _sort_ is "true" then the names
will be sorted in ascending order.  
_dtype_ must be set to:  
  dir = 0 files and directories  
  dir = 1 just files  
  dir = 2 just directories  
Note: cary\_dir makes use of the cary struct.

```c
    cary d = cary_dir("/home/user/", 1, true);
    cary_display(d);
    cary_del(d);

```

--------------------------------------------------------------------------------------------------

<a name="mycother"></a>
## Utility & Miscellaneous (_myc.h_) [^](#top 'top')

<a name="ARRSIZE"></a>
### ARRSIZE(x)
>Macro expands to: `(sizeof(x) / sizeof((x)[0]))`  
>For array size.

<a name="isort"></a>
### void isort (int values[], int n)
>Sorts an array of n integer _values_.

<a name="ssort"></a>
### void ssort (const char\* arr[], int n, bool case)
>Sorts an array of n strings. if _case_ is "true" the
sort will be case-insensitive.

<a name="dsort"></a>
### void dsort (double values[], int n)
>Sorts an array of n doubles.

<a name="date"></a>
### char \*date (char \*format)
>Returns a date string in a strftime
format.  
(see _man strftime_ for the format
codes.)

```c
    puts(date("%B %F %r")); // February 2022-02-05 10:29:17 AM
```

<a name="timeout"></a>
### void timeout (int sec, function)
>_timeout_ sets up a SIGALRM to call _function_
after _sec_ seconds.

```c
    void timeout_hand() {
       // user timout handler function
      // code actions to occur
     // at end of timeout
    }

    . . .

    timeout(6, timeout_hand);  // call "timout_hand" every 6 seconds

    . . .

```

<a name="multifree"></a>
### void multifree(int num, ...)
>Free multiple (_num_) heap pointers.  
Also sets to NULL.

```c
  char *w1 = malloc(1000);
  char *w2 = malloc(2000);

  multifree(2, w1, w2);

```
<a name="ERRMSG"></a>
### ERRMSG(a, b, c) (errmsg(a, b, c, __LINE__))
>Macro to display an error event  
errmsg works with the ERRMSG macro  
use ERRMSG with three arguments:  
1> the return code to be checked  
2> _true_ or _false_ to terminate the program  
3> an additional error or debug message (string)  

```c

  if (realpath("../nope", fpath) == NULL) {
    ERRMSG(errno, true, "realpath returned NULL");
  } else {
    puts(fpath);
  }

/* OUTPUT
  ERRMSG near line: 40, errno: 2 No such file or directory
  realpath returned NULL
  Program Exited
*/

```


-------------------------------------------------------------------------------------------------------

<a name="mydb"></a>
## DATABASE Sqlite3 _mydb.h_ [^](#top 'top')

<a name="mydb_open"></a>
### void mydb\_open(char \* dbname)
>Opens an Sqlite3 database using file
name is *dbname*.  
Checks for existing database file.  
Exits with error if open fails.  
_db_ is the database connection pointer.  
To open another database the open one must
be closed first with sqlite3_close(db);

<a name="mydb_count"></a>
### int mydb\_count(char \*tablename, char \*where)
>Returns a count(\*) result. Uses a *where* clause.  
Use empty quotes in where clause to count all rows.

```c
  mydb_open("guns.db");
  printf("total rows = %i\n\n", mydb_count("guns", ""));
  printf("total rows = %i\n\n", mydb_count("guns", "where sex = 'Female'"));
```

<a name="mydb_names"></a>
### int mydb\_names(char \*tablename)
Loads an array of strings (*mydb_col*)
containing the text of the column names.  
Returns the count of columns.
```c
    mydb_open("guns.db");
    rc = mydb_names("guns");  // table name is 'guns'

    printf("number of columns = [%d]\n", rc);

    for (int x=0; x < rc; x++) {
        printf("%s\n", mydb_col[x]);
    }
```
#### Template

The following function template must be used to process the row/col
values after using the sqlite3_exec function. Have one or many.
```c
/*
user function to handle result set
note:    may need many different callback functions and/or
         use the qid parameter to direct action in one callback
*/
static int resultset(void *qid, int argc, char **argv, char **col) {
    int i;

    // (const char*)qid;  // can use for process control or heading

    // one row: process each column in order of sql statement
    for(i = 0; i<argc; i++) {
       printf("%s = %s\n", col[i], argv[i] ? argv[i] : "NULL");
    }
    return 0;
}
```


#### Example

```c
/***
Example using mydb.h functions and above template ...
***/
    int rc = 0;

    mydb_open("guns.db");  // the database pointer is now 'db'

    //char * sql = "select distinct education from guns";

    rc = sqlite3_exec(db,
                          "select distinct education from guns",
                          resultset,
                          "ITEM>>>>", // or whatever
                          0);  // or &err_msg

    printf("rc from exec was [%d]\n\n", rc);  // 1==ERROR, 0==SUCCESS

    printf("total rows = %i\n\n", mydb_count("guns", ""));  // -1==FAIL

    rc = mydb_names("guns");  // -1==FAIL | loads **mydb_col

    printf("number of columns = [%d]\n", rc);

    for (int x=0; x < rc; x++) {
        printf("%s\n", mydb_col[x]);
    }

    sqlite3_close(db);

```

-----------------------------------------------------------------------------------------

<a name="mynet"></a>
## NET/WEB functions _mynet.h_ [^](#top 'top')

<a name="webpage"></a>
### bool webpage(char \*mybuffer, int sz, char \*url)
>Returns the web page code text from _url_
into _mybuffer_.  
_sz_ is buffer size of _mybuffer_.

```c
  char *pagebuf;
  pagebuf = calloc(10000, sizeof(char*));
  if (!webpage(pagebuf, 10000, "https://example.com")) {
    printf("exiting because of webpage failure\n");
    exit(1);
  } else {
    printf("webpage success!\n%s\n", pagebuf);
  }
  
```

<a name="webget"></a>
### bool webget(char \*request)
>Perform a GET request with _key-value_ querystring.

```c
    concat(dat, 5, "https://somewhere.net/test/fromgetcurl.php",
                   "?data=",
                   urlencode(wrk, "1st-key is data"),
                   "&var=",
                   urlencode(wr2, "2nd-key is 'var'...")
                   );

    if (!webget(dat)) {
      printf("exiting because of webget failure\n");
      exit(EXIT_FAILURE);
    } else {
      printf("webget success!\n");
    }

```

<a name="webpost"></a>
### bool webpost(char \*url, char \*vp_data)
>Perform a POST request to _url_ with
payload *vp_data*.

```c
  char url[] = "https://somewhere.net/test/frompostcurl.php";
 
  // prepare querystring
  concat(dat, 4, "data=",
                 urlencode(wr1, "content & ampersand!"),
                 "&var=",
                 urlencode(wr2, "second variable content!!!!"));

  // post to server
  if (!webpost(url, dat)) {
    printf("exiting because of webpost failure\n");
    exit(1);
  } else {
    printf("webpost success!\n");
  }

```

<a name="webbrowser"></a>
### bool webbrowser(const char \*url)
>Opens the website at _url_ in the
current system default browser.

```c
    if (!webbrowser("https://tekvow.net")) {
      printf("exiting because of webbrowser mynet.h failure\n");
      exit(1);
    } else {
      printf("webbrowser success!\n");
    }

```


---

_end of document_
