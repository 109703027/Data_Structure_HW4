for seed in 1 2 3 4 5
do
    ./a.out -connect_file connect$seed.txt -coordinate_file coordinate$seed.txt -save averDis2.csv
done
