## 用来实现stm32+kq130F的电力线载波通讯
串口库已经完成，放在in_bed的bolib下
#### ------------------update 2017/03/26---------------------------
`TODO`目前电力线载波的通讯只在reset后的第一下有用。原因可能是发送的buf里面的数据格式需要是u8，而昨天写的是char，也有可能是因为keil的中文编码用的不是utf-8，产生了莫名其妙的错误。今晚回去之后改改看
