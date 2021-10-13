## property用于装饰器修饰类成员函数时，有两个作用：
 - 将类成员函数变成类成员变量
 - 将该属性被约定成一个只读属性

## property()在类中返回属性值，用法如下：
 - c.x调用的是getx函数
 - c.x=v调用的是setx函数
 - del c.x调用的是delx函数
```python
class C(object):
    def getx(self):
       ...
    x = property(getx, setx, delx, "x property")
c = C()
```
