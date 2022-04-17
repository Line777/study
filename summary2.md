# 总结

本周主要就是学习数据库和八股还有刷题。将B站上黑马的mysql课程看完了。然后主要了解了mysql日志，索引，索引优化等方面的知识。
## Master-Slave
>> MySQL数据库自身提供的主从复制功能可以方便的实现数据的多处自动备份，实现数据库的拓展。多个数据备份不仅可以加强数据的安全性，通过实现读写分离还能进一步提升数据库的负载性能。
在一主多从的数据库体系中，多个从服务器采用异步的方式更新主数据库的变化，业务服务器在执行写或者相关修改数据库的操作是在主服务器上进行的，读操作则是在各从服务器上进行。

实现MySQL主从复制需要进行的配置：

主服务器：

开启二进制日志

配置唯一的server-id

获得master二进制日志文件名及位置

创建一个用于slave和master通信的用户账号

从服务器：

配置唯一的server-id

使用master分配的用户账号读取master二进制日志

启用slave服务

同时主节点为每个I/O线程启动一个dump线程，用于向其发送二进制事件，并保存至从节点本地的中继日志中，从节点将启动SQL线程从中继日志中读取二进制日志，在本地重放，使得其数据和主节点的保持一致，

最后I/OThread和SQLThread将进入睡眠状态，等待下一次被唤醒。
## reactor
事件驱动（event handling）

可以处理一个或多个输入源（one or more inputs）

通过Service Handler同步的将输入事件（Event）采用多路复用分发给相应的Request Handler（多个）处理

Reactor 将I/O事件分派给对应的Handler

Acceptor 处理客户端新连接，并分派请求到处理器链中

Handlers 执行非阻塞读/写 任务

// 主线程维护连接

  public void run() {
  
      try {
      
          while (true) {
          
              Socket socket = serverSocket.accept();
              
              //提交线程池处理
              
              executorService.submit(new Handler(socket));
              
          }
          
      } catch (Exception e) {
      
          e.printStackTrace();
          
      }
      
  }
​
  // 处理读写服务
  
  class Handler implements Runnable {
  
      public void run() {
      
          try {
          
              //获取Socket的输入流，接收数据
              
              BufferedReader buf = new BufferedReader(new InputStreamReader(socket.getInputStream()));
              
              String readData = buf.readLine();
              
              while (readData != null) {
              
                  readData = buf.readLine();
                  
                  System.out.println(readData);
                  
              }
              
          } catch (Exception e) {
          
              e.printStackTrace();
          }
      }
  }
