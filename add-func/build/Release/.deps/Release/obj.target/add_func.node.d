cmd_Release/obj.target/add_func.node := g++ -shared -pthread -rdynamic -m64  -Wl,-soname=add_func.node -o Release/obj.target/add_func.node -Wl,--start-group Release/obj.target/add_func/math.o -Wl,--end-group 
