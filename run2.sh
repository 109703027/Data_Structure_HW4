for seed in 0 2 7 30 77
do
    for n in 75
    do
        ./a.out -connect_file connect$seed\_$n.txt -coordinate_file coordinate$seed\_$n.txt -save averDis2.csv
    done
done
