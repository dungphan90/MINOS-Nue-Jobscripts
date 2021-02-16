void makePARAMLIST() {
    // See https://www.overleaf.com/project/5f3aa6a1fb441d000143b46a for explanation of these values.
    std::string dcp_array[4] = {"0.0000", "0.7854", "1.5708", "4.7124"};
    std::string th34_array[3] = {"0.0000", "0.7854", "1.5708"};
    std::string th13_array[5] = {"0.1434", "0.1458", "0.1482", "0.1506", "0.1530"};
    std::string th23_array[5] = {"0.6330", "0.6740", "0.7150", "0.9170", "1.1190"};
    std::string dmsq32_array[5] = {"0.00222", "0.00231", "0.00240", "0.00248", "0.00256"};

    std::string dcp14 = "0.0000";
    std::string dcp24 = "0.0000";

    for (unsigned int i_dcp = 0; i_dcp < 4; i_dcp++) {
        for (unsigned int i_th34 = 0; i_th34 < 3; i_th34++) {
            for (unsigned int i_th13 = 0; i_th13 < 5; i_th13++) {
                for (unsigned int i_th23 = 0; i_th23 < 5; i_th23++) {
                    for (unsigned int i_dmsq32 = 0; i_dmsq32 < 5; i_dmsq32++) {
                        std::cout << Form("%s, %s, %s, %s, %s, %s, %s", dcp_array[i_dcp].c_str(),
                                                                        dcp14.c_str(),
                                                                        dcp24.c_str(),
                                                                        th34_array[i_th34].c_str(),
                                                                        th13_array[i_th13].c_str(),
                                                                        th23_array[i_th23].c_str(),
                                                                        dmsq32_array[i_dmsq32].c_str()) << std::endl;
                    }
                }
            }
        }
    }
}