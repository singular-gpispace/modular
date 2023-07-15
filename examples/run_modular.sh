#cd temp
#rm * 
#cd ..
gspc-monitor --port 9876 &
SINGULARPATH=/home/hbn/test/framework_install Singular new_run_modular.sing
