for seed in 0 2 7 30 77
do
    for n in 200 500 1000
    do
        ./a.out -seed $seed -n_index $n -node_file node$seed\_$n.txt -connect_file connect$seed\_$n.txt -coordinate_file coordinate$seed\_$n.txt
    done
done
