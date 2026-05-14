#include "../include/philosophers.h"

const char    *philo_name(size_t id)
{
    const char* philo_library[100] = {
    PH_0,  PH_1,  PH_2,  PH_3,  PH_4,  PH_5,  PH_6,  PH_7,  PH_8,  PH_9,
    PH_10, PH_11, PH_12, PH_13, PH_14, PH_15, PH_16, PH_17, PH_18, PH_19,
    PH_20, PH_21, PH_22, PH_23, PH_24, PH_25, PH_26, PH_27, PH_28, PH_29,
    PH_30, PH_31, PH_32, PH_33, PH_34, PH_35, PH_36, PH_37, PH_38, PH_39,
    PH_40, PH_41, PH_42, PH_43, PH_44, PH_45, PH_46, PH_47, PH_48, PH_49,
    PH_50, PH_51, PH_52, PH_53, PH_54, PH_55, PH_56, PH_57, PH_58, PH_59,
    PH_60, PH_61, PH_62, PH_63, PH_64, PH_65, PH_66, PH_67, PH_68, PH_69,
    PH_70, PH_71, PH_72, PH_73, PH_74, PH_75, PH_76, PH_77, PH_78, PH_79,
    PH_80, PH_81, PH_82, PH_83, PH_84, PH_85, PH_86, PH_87, PH_88, PH_89,
    PH_90, PH_91, PH_92, PH_93, PH_94, PH_95, PH_96, PH_97, PH_98, PH_99
};
    if (id >= 0 && id < 100)
        return (philo_library[id]);
    return (NULL);
}

char    *find_philo(size_t id)
{
    int i;
    int r;

    i = id % 100;
    r = 
    printf("%i\n%i\n\n\n", i, r);
    return ((char *)philo_name(id));
}