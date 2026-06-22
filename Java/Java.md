
![[Pasted image 20260423161122.png]]


![[Pasted image 20260423161705.png]]


![[Pasted image 20260423161801.png]]


![[Pasted image 20260423161927.png]]


![[Pasted image 20260423162529.png]]


![[Pasted image 20260423163715.png]]


![[Pasted image 20260423164913.png]]


![[Pasted image 20260423170219.png]]


![[Pasted image 20260423170732.png]]

[第4章-数组-06-数组的动态初始化_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1TJxCzSEEZ?spm_id_from=333.788.player.switch&vd_source=d73b69d231b0a0908c553f1bf14e36e6&p=61)


![[Pasted image 20260424084234.png]]
random

![[Pasted image 20260424084542.png]]

![[Pasted image 20260424084745.png]]


![[Pasted image 20260424085153.png]]



![[Pasted image 20260424085417.png]]



![[Pasted image 20260430093301.png]]

![[Pasted image 20260430093243.png]]

![[Pasted image 20260604163640.png]]

![[Pasted image 20260604165416.png]]

![[Pasted image 20260611154730.png]]


static
![[Pasted image 20260611160117.png]]


![[Pasted image 20260611164937.png]]


![[Pasted image 20260611165947.png]]


![[Pasted image 20260611170400.png]]


```java
**// 普通类
class Dog {
    void eat() {
        System.out.println("狗在吃东西");
    }
}

// 抽象类
abstract class Animal {
    abstract void makeSound(); // 抽象方法，没有方法体

    void sleep() {
        System.out.println("动物在睡觉");
    }
}

// 接口
interface Run {
    void run();
}

// 子类继承抽象类，并实现接口
class Cat extends Animal implements Run {
    public void makeSound() {
        System.out.println("猫叫：喵喵");
    }

    public void run() {
        System.out.println("猫在跑");
    }
}**
```

