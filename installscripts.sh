#!/bin/bash

case $1 in
    install)

        mkdir bin
        cd bin
        touch run.sh

cat <<- EOF > run.sh
#!/bin/bash
find /etc/init.d/ -executable -type f
EOF

        chmod +x run.sh && ./run.sh
    ;;

    uninstall)
        if [ -f bin/run.sh ]; then
            cd bin
            rm *
            cd ..
            rmdir bin
        fi
    ;;
    
    *)
        echo "wrong argument"
        exit 1 

esac

exit 0


