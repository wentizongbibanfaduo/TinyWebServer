#include "config.h"

Config::Config(){
    //端口号,默认9006
    m_port = 9006;

    //日志写入方式，默认同步
    m_log_write = 0;

    //触发组合模式,默认listenfd LT + connfd LT
    m_trig_mode = 0;

    //listenfd触发模式，默认LT
    m_listen_trig_mode = 0;

    //connfd触发模式，默认LT
    m_conn_trig_mode = 0;

    //优雅关闭链接，默认不使用
    m_opt_linger = 0;

    //数据库连接池数量,默认8
    m_sql_nums = 8;

    //线程池内的线程数量,默认8
    m_thread_nums = 8;

    //关闭日志,默认不关闭
    m_close_log = 0;

    //并发模型,默认是proactor
    m_actor_model = 0;

    m_user = "root";
    m_password = "root";
    m_database_name = "yourdb";
}

void Config::parse_arg(int argc, char* argv[]){
    int opt;
    const char *str = "p:l:m:o:s:t:c:a:";
    while ((opt = getopt(argc, argv, str)) != -1)
    {
        switch (opt)
        {
        case 'p':
        {
            m_port = atoi(optarg);
            break;
        }
        case 'l':
        {
            m_log_write = atoi(optarg);
            break;
        }
        case 'm':
        {
            m_trig_mode = atoi(optarg);
            break;
        }
        case 'o':
        {
            m_opt_linger = atoi(optarg);
            break;
        }
        case 's':
        {
            m_sql_nums = atoi(optarg);
            break;
        }
        case 't':
        {
            m_thread_nums = atoi(optarg);
            break;
        }
        case 'c':
        {
            m_close_log = atoi(optarg);
            break;
        }
        case 'a':
        {
            m_actor_model = atoi(optarg);
            break;
        }
        default:
            break;
        }
    }
}