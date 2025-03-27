首先进入even.sh配置下各种路径，然后运行

source ./even.sh

然后

make

没有错误的话就是对的

针对这个工程，还要在设备树中添加
```
	a_led_test {
		#address-cells = <1>;
		#size-cells = <1>;
		compatible = "fire,rgb_led_red_root";
		
		rgb_led_red@0x0209C000{
			compatible = "fire,rgb_led_red";
			reg = <0x0209C000 0x00000020>;
			status = "okay";
		};
	};
```
然后编译设备树
将编译好的设备树替换掉板子上的设备树文件，重启板子



