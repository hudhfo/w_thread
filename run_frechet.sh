mpirun -n 2 ./pmcl3d \
 -X 200 -Y 200 -Z 160 -x 1 -y 2 \
 --TMAX 15.0   --DH 200.0 --DT 0.01 \
 --NSRC 1 --NST 80  \
--IFAULT 1 --MEDIASTART 2 --READ_STEP 80 --WRITE_STEP 1500 \
--NSKPX 1 --NSKPY 1   --NTISKP 1   -c output_ckp/ckp   -o output_sfc   --INSRC input/source_frechetkernel   --INVEL input/mesh_frechetkernel
