## Logger
Example of use

1. Put all files into your project.
2. Include headers

```cpp
  #include "abstractlogger.h"
  #include "seriallogger.h"
  #include "filelogger.h"
  #include "udplogger.h"
```

3. Create instances for required logs

```cpp
    AbstractLogger* udpLogger = new UdpLogger(12345);
    AbstractLogger* fileLogger = new FileLogger("log.txt");
    AbstractLogger* serialLogger = new SerialLogger("COM1", 921600);
```

4. Write data to log

```cpp
    udpLogger->write("Hello, udp!");
    fileLogger->write("Hello, txt!");
    serialLogger->write("Hi, serial!");
```

5. Delete instances 
```cpp
    udpLogger->deleteLater();
    fileLogger->deleteLater();
    serialLogger->deleteLater();
```
