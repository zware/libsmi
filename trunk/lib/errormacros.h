#define ERR_INTERNAL                             0
#define ERR_MAX_LEX_DEPTH                        1
#define ERR_LEX_UNEXPECTED_CHAR                  2
#define ERR_OUT_OF_MEMORY                        3
#define ERR_OTHER_ERROR                          4
#define ERR_ILLEGAL_KEYWORD                      5
#define ERR_ID_ENDS_IN_HYPHEN                    6
#define ERR_LEADING_ZEROS                        7
#define ERR_NUMBER_TOO_LARGE                     8
#define ERR_HEX_ENDS_IN_B                        9
#define ERR_MODULENAME_64                        10
#define ERR_MODULENAME_32                        11
#define ERR_TYPENAME_64                          12
#define ERR_TYPENAME_32                          13
#define ERR_OIDNAME_64                           14
#define ERR_OIDNAME_32                           15
#define ERR_ENUMNAME_64                          16
#define ERR_ENUMNAME_32                          17
#define ERR_BITNAME_64                           18
#define ERR_BITNAME_32                           19
#define ERR_UCIDENTIFIER_64                      20
#define ERR_LCIDENTIFIER_64                      21
#define ERR_TRAP_TYPE                            22
#define ERR_TOO_MANY_MODULE_IDENTITIES           23
#define ERR_NO_MODULE_IDENTITY                   24
#define ERR_OID_DEFVAL_TOO_LONG                  25
#define ERR_INVALID_SMIV1_ACCESS                 26
#define ERR_INVALID_SMIV2_ACCESS                 27
#define ERR_SMIV2_WRITE_ONLY                     28
#define ERR_SMIV1_WRITE_ONLY                     29
#define ERR_INVALID_NOTIFICATION_VARIATION_ACCESS 30
#define ERR_INVALID_OBJECT_VARIATION_ACCESS      31
#define ERR_INVALID_VARIATION_ACCESS             32
#define ERR_NOTIFICATION_VARIATION_SYNTAX        33
#define ERR_NOTIFICATION_VARIATION_WRITESYNTAX   34
#define ERR_DEFVAL_SYNTAX                        35
#define ERR_NOTIFICATION_VARIATION_DEFVAL        36
#define ERR_NOTIFICATION_VARIATION_CREATION      37
#define ERR_MODULE_IDENTITY_NOT_FIRST            38
#define ERR_INVALID_SMIV1_STATUS                 39
#define ERR_INVALID_SMIV2_STATUS                 40
#define ERR_INVALID_CAPABILITIES_STATUS          41
#define ERR_OIDNAME_INCLUDES_HYPHEN              42
#define ERR_ILLEGAL_CHAR_IN_STRING               43
#define ERR_BIN_STRING_MUL8                      44
#define ERR_HEX_STRING_MUL2                      45
#define ERR_FLUSH_DECLARATION                    46
#define ERR_MAX_ACCESS_IN_SMIV1                  47
#define ERR_ACCESS_IN_SMIV2                      48
#define ERR_UNWANTED_MODULE                      49
#define ERR_MODULE_NOT_FOUND                     50
#define ERR_OBJECT_IDENTIFIER_REGISTERED         51
#define ERR_OPENING_INPUTFILE                    52
#define ERR_ILLEGAL_INPUTFILE                    53
#define ERR_UNKNOWN_OIDLABEL                     54
#define ERR_SINGLE_SUBIDENTIFIER                 55
#define ERR_SUBIDENTIFIER_VS_OIDLABEL            56
#define ERR_EXISTENT_OBJECT                      57
#define ERR_IDENTIFIER_NOT_IN_MODULE             58
#define ERR_MACRO                                59
#define ERR_CHOICE                               60
#define ERR_TYPE_SMI                             61
#define ERR_TYPE_TAG                             62
#define ERR_MACRO_ALREADY_EXISTS                 63
#define ERR_EXPORTS                              64
#define ERR_ILLEGALLY_QUALIFIED                  65
#define ERR_MISSING_DESCRIPTION                  66
#define ERR_OIDLABEL_NOT_FIRST                   67
#define ERR_UNKNOWN_TYPE                         68
#define ERR_LOCATION                             69
#define ERR_UNKNOWN_LOCATION_TYPE                70
#define ERR_ILLEGAL_RANGE_FOR_PARENT_TYPE        71
#define ERR_ILLEGAL_SIZE_FOR_PARENT_TYPE         72
#define ERR_ILLEGAL_ENUM_FOR_PARENT_TYPE         73
#define ERR_SMIV2_SIGNED_NUMBER_RANGE            74
#define ERR_SMIV2_UNSIGNED_NUMBER_RANGE          75
#define ERR_INTEGER32_TOO_LARGE                  76
#define ERR_UNEXPECTED_VALUETYPE                 77
#define ERR_SMI_NOT_SUPPORTED                    78
#define ERR_SMING_NOT_SUPPORTED                  79
#define ERR_UNUSED_IMPORT                        80
#define ERR_MACRO_NOT_IMPORTED                   81
#define ERR_IMPLICIT_NODE                        82
#define ERR_SCALAR_READCREATE                    83
#define ERR_NAMEDNUMBER_INCLUDES_HYPHEN          84
#define ERR_NAMEDBIT_INCLUDES_HYPHEN             85
#define ERR_REDEFINITION                         86
#define ERR_EXT_REDEFINITION                     87
#define ERR_CASE_REDEFINITION                    88
#define ERR_EXT_CASE_REDEFINITION                89
#define ERR_PREVIOUS_DEFINITION                  90
#define ERR_INVALID_FORMAT                       91
#define ERR_REFINEMENT_ALREADY_EXISTS            92
#define ERR_OPTIONALGROUP_ALREADY_EXISTS         93
#define ERR_ILLEGAL_OID_DEFVAL                   94
#define ERR_UNEXPECTED_TYPE_RESTRICTION          95
#define ERR_UNKNOWN_CONFIG_CMD                   96
#define ERR_OPAQUE_OBSOLETE                      97
#define ERR_DATE_CHARACTER                       98
#define ERR_DATE_LENGTH                          99
#define ERR_DATE_VALUE                           100
#define ERR_DATE_YEAR_2DIGITS                    101
#define ERR_DATE_YEAR                            102
#define ERR_DATE_MONTH                           103
#define ERR_DATE_DAY                             104
#define ERR_DATE_HOUR                            105
#define ERR_DATE_MINUTES                         106
#define ERR_DATE_IN_FUTURE                       107
#define ERR_DATE_IN_PAST                         108
#define ERR_INTEGER_IN_SMIV2                     109
#define ERR_MODULE_ALREADY_LOADED                110
#define ERR_BASETYPE_NOT_IMPORTED                111
#define ERR_BASETYPE_UNKNOWN                     112
#define ERR_ROW_SUBID_ONE                        113
#define ERR_ROWNAME_ENTRY                        114
#define ERR_TABLENAME_TABLE                      115
#define ERR_SMIV2_TYPE_ASSIGNEMENT               116
#define ERR_ILLEGAL_IMPORT                       117
#define ERR_SMIV2_NESTED_TEXTUAL_CONVENTION      118
#define ERR_TABLE_ACCESS                         119
#define ERR_ROW_ACCESS                           120
#define ERR_ENUM_SUBTYPE                         121
#define ERR_BITS_SUBTYPE                         122
#define ERR_ENUM_NAME_REDEFINITION               123
#define ERR_ENUM_NUMBER_REDEFINITION             124
#define ERR_BITS_NAME_REDEFINITION               125
#define ERR_BITS_NUMBER_REDEFINITION             126
#define ERR_BITS_NUMBER_TOO_LARGE                127
#define ERR_BITS_NUMBER_LARGE                    128
#define ERR_RANGE_OUT_OF_BASETYPE                129
#define ERR_RANGE_OVERLAP                        130
#define ERR_RANGES_NOT_ASCENDING                 131
#define ERR_EXCHANGED_RANGE_LIMITS               132
#define ERR_INDEX_BASETYPE                       133
#define ERR_INDEX_TOO_LARGE                      134
#define ERR_INDEX_NO_RANGE                       135
#define ERR_INDEX_NO_RANGE_MOD                   136
#define ERR_INDEX_NO_SIZE                        137
#define ERR_INDEX_NO_SIZE_MOD                    138
#define ERR_INDEX_RANGE_NEGATIVE                 139
#define ERR_INDEX_ENUM_NEGATIVE                  140
#define ERR_EMPTY_DESCRIPTION                    141
#define ERR_INDEX_NOT_COLUMN                     142
#define ERR_AUGMENT_NESTED                       143
#define ERR_AUGMENT_NO_ROW                       144
#define ERR_NODE_NOT_IN_GROUP                    145
#define ERR_NOTIFICATION_NOT_IN_GROUP            146
#define ERR_INVALID_GROUP_MEMBER                 147
#define ERR_MIXED_GROUP_MEMBERS                  148
#define ERR_BAD_LOWER_IDENTIFIER_CASE            149
#define ERR_UNDERSCORE_IN_IDENTIFIER             150
#define ERR_OID_REUSE                            151
#define ERR_OID_REGISTERED                       152
#define ERR_OID_RECURSIVE                        153
