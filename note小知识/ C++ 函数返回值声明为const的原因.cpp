const int &a(int &b);
int &a (int &b);

const关键字的作用就是对数据的读取保护，防止恶意修改。函数接口前面加const自然就是对返回值的一个读取保护
当函数返回引用类型时，没有复制返回值。相反，返回的是对象本身。

const int &a(int &b); 做为返回值使用，说明函数的返回值是不 能被修改的，
在取得返回值时应用const int  &c = a(b);对不同参数定义时不同的形式，
//http://www.cnblogs.com/Azhu/p/4352613.html
//http://blog.csdn.net/zhjxin1800/article/details/7584375

其目的就是为了实现用户自定义类型与内置类型最大限度的保持一致性。

比如操作 a+b = c; 对于内置类型在编译时，会弹出不能对lvalue进行赋值的错误；然而对于用户自定义类型，比如class A{}; 当对A定义了形式为

A operator+(const A& lhs, const A& rhs){};的接口时，编译和连接过程不会出现内置类型弹出的错误。

解决办法就是给函数的返回值加上const标识，指定不能对函数的返回值进行赋值，如此一来，对于自定义类型，再进行a+b = c;操作时，编译过程也会报错。

在现实的编码中，可能谁也不会敲出a+b=c;这样的单纯语句，但是你不可能保证在你想表达if(a+b == c)时，却一时马虎写成了if(a+b = c)，程序能够编译连接通过，但不是按你想要的逻辑运行，于是问题就出现了，这个问题应该再编译时期就被发现的。