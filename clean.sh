cd ./trace_debug
bash clean.sh
cd ../trace_loop
bash clean.sh
cd ..
make fclean -C ./files
printf "clean done"
