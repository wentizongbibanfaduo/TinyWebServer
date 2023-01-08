#ifndef CONFIG_H
#define CONFIG_H

#include <unistd.h>
#include <stdlib.h>
#include <string>

using namespace std;

class Config
{
public:
    Config();
    ~Config(){};

    void parse_arg(int argc, char*argv[]);

    //端口号
    int m_port;

    //日志写入方式
    int m_log_write;

    //触发组合模式
    int m_trig_mode;

    //listenfd触发模式
    int m_listen_trig_mode;

    //connfd触发模式
    int m_conn_trig_mode;

    //优雅关闭链接
    int m_opt_linger;

    //数据库连接池数量
    int m_sql_nums;

    //线程池内的线程数量
    int m_thread_nums;

    //是否关闭日志
    int m_close_log;

    //并发模型选择
    int m_actor_model;

    //登陆数据库用户名
    std::string m_user;

    //登陆数据库密码         
    std::string m_password;

    //使用数据库名    
    std::string m_database_name; 
};

#endif