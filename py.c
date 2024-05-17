#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    uint8_t *py_input; // 输入的字符串
    uint8_t *py;       // 对应的拼音
    uint8_t *pymb;     // 码表
} py_index;

const uint8_t PY_mb_space[] = {""};
const uint8_t PY_mb_a[] = {"啊阿腌吖嗄呵腌\0"};
const uint8_t PY_mb_ai[] = {"爱埃挨哎唉哀皑癌蔼矮艾碍隘捱嫒霭\0"};
const uint8_t PY_mb_an[] = {"安俺按暗岸案鞍氨胺埯庵桉鹌黯\0"};
const uint8_t PY_mb_ang[] = {"昂盎肮\0"};
const uint8_t PY_mb_ao[] = {"凹敖熬翱袄傲奥懊澳坳嗷鳌鏖遨媪\0"};
const uint8_t PY_mb_ba[] = {"八巴爸拔芭捌扒叭吧笆疤跋靶把耙坝霸罢岜鲅\0"};
const uint8_t PY_mb_bai[] = {"白柏百摆佰败拜稗伯掰\0"};
const uint8_t PY_mb_ban[] = {"半办斑班搬扳般颁板版扮拌伴瓣绊阪坂\0"};
const uint8_t PY_mb_bang[] = {"邦帮梆榜膀绑棒磅蚌镑傍谤蒡\0"};
const uint8_t PY_mb_bao[] = {"包宝保抱报暴苞胞褒剥薄雹堡饱豹鲍爆刨炮孢煲鸨褓\0"};
const uint8_t PY_mb_bei[] = {"背贝北倍杯碑悲卑辈钡狈备惫焙被臂孛陂蓓呗悖\0"};
;
const uint8_t PY_mb_ben[] = {"本笨奔苯\0"};
const uint8_t PY_mb_beng[] = {"蚌崩绷甭泵蹦迸堋嘣\0"};
const uint8_t PY_mb_bi[] = {"逼鼻比鄙笔彼碧蓖蔽毕毙毖币庇痹闭匕敝弊必辟壁臂避陛秘泌芘荜荸吡哔愎濞妣婢璧裨\0"};
const uint8_t PY_mb_bian[] = {"边编贬便变卞鞭扁辨辩辫遍匾汴煸褊\0"};
const uint8_t PY_mb_biao[] = {"表标彪膘婊骠杓飙裱\0"};
const uint8_t PY_mb_bie[] = {"别鳖憋\0"};
const uint8_t PY_mb_bin[] = {"彬斌濒滨宾摈缤玢槟殡鬓\0"};
const uint8_t PY_mb_bing[] = {"兵冰柄丙秉饼炳病并屏禀槟\0"};
const uint8_t PY_mb_bo[] = {"柏百剥薄博玻菠卜播拨钵波勃搏铂箔伯帛舶脖膊渤泊驳孛蕃啵饽\0"};
const uint8_t PY_mb_bu[] = {"不布步堡捕卜哺补埠簿部怖埔\0"};
const uint8_t PY_mb_ca[] = {"擦\0"};
const uint8_t PY_mb_cai[] = {"才财睬猜裁材踩采彩菜蔡\0"};
const uint8_t PY_mb_can[] = {"餐参蚕残惭惨灿璨\0"};
const uint8_t PY_mb_cang[] = {"苍舱仓沧藏\0"};
const uint8_t PY_mb_cao[] = {"草操糙槽曹嘈漕\0"};
const uint8_t PY_mb_ce[] = {"侧册测厕策恻\0"};
const uint8_t PY_mb_cen[] = {"参岑涔\0"};
const uint8_t PY_mb_ceng[] = {"层蹭曾\0"};
const uint8_t PY_mb_cha[] = {"插叉茬茶查碴搽察岔差诧刹喳衩姹杈\0"}; // todo
const uint8_t PY_mb_chai[] = {"差拆柴豺侪钗瘥虿龇\0"};
const uint8_t PY_mb_chan[] = {"产阐颤搀掺蝉馋谗缠铲孱单冁谄蒇廛忏潺澶羼婵觇禅镡蟾躔\0"};
const uint8_t PY_mb_chang[] = {"长厂昌猖场尝常偿肠敞畅唱倡伥鬯苌菖徜怅惝阊娼嫦昶氅鲳\0"};
const uint8_t PY_mb_chao[] = {"超抄钞朝嘲潮巢吵炒绰剿怊晁耖\0"};
const uint8_t PY_mb_che[] = {"车扯撤掣彻澈坼屮砗\0"};
const uint8_t PY_mb_chen[] = {"郴臣辰尘晨忱沉陈趁衬称谌谶抻嗔宸琛榇碜龀\0"};
const uint8_t PY_mb_cheng[] = {"撑称城橙成呈乘程惩澄诚承逞骋秤盛丞埕噌徵枨柽塍瞠铖铛裎蛏酲\0"};
const uint8_t PY_mb_chi[] = {"吃痴持匙池迟弛驰耻齿侈尺赤翅斥炽笞叱哧傺坻墀茌啻嗤彳饬媸敕眵鸱瘛褫蚩螭篪豉踟魑\0"};
const uint8_t PY_mb_chong[] = {"充冲虫崇宠种重茺忡憧铳舂艟雠\0"};
const uint8_t PY_mb_chou[] = {"抽酬丑畴踌稠愁筹仇绸瞅臭俦帱惆瘳雠\0"};
const uint8_t PY_mb_chu[] = {"出初橱厨躇锄雏滁除楚础储矗搐触处畜亍刍怵憷绌杵楮樗褚蜍蹰黜\0"};
const uint8_t PY_mb_chuai[] = {"揣搋嘬膪踹\0"};
const uint8_t PY_mb_chuan[] = {"川穿椽传船喘串舛遄巛氚钏舡\0"};
const uint8_t PY_mb_chuang[] = {"疮窗幢床闯创怆疒\0"};
const uint8_t PY_mb_chui[] = {"吹炊捶锤垂陲棰槌\0"};
const uint8_t PY_mb_chun[] = {"春椿醇唇淳纯蠢莼鹑蝽\0"};
const uint8_t PY_mb_chuo[] = {"戳绰啜辶辍踔龊\0"};
const uint8_t PY_mb_ci[] = {"此刺赐次伺差疵茨磁雌辞慈瓷词兹茈呲祠鹚粢糍\0"};
const uint8_t PY_mb_cong[] = {"从丛聪葱囱匆苁淙骢琮璁枞\0"};
const uint8_t PY_mb_cou[] = {"凑楱辏腠\0"};
const uint8_t PY_mb_cu[] = {"粗醋簇促蔟徂猝殂酢蹙蹴\0"};
const uint8_t PY_mb_cuan[] = {"蹿篡窜攒汆撺爨镩\0"};
const uint8_t PY_mb_cui[] = {"摧崔催脆瘁粹淬翠萃啐悴璀榱毳隹\0"};
const uint8_t PY_mb_cun[] = {"村存寸忖皴\0"};
const uint8_t PY_mb_cuo[] = {"磋撮搓措挫错厝嵯脞锉矬痤瘥鹾蹉躜\0"};
const uint8_t PY_mb_da[] = {"大搭达答瘩打耷哒嗒怛妲沓疸褡笪靼鞑\0"};
const uint8_t PY_mb_dai[] = {"大呆歹傣戴带殆代贷袋待逮怠黛埭甙呔岱迨骀绐玳\0"};
const uint8_t PY_mb_dan[] = {"耽担丹单郸掸胆旦氮但惮淡诞弹蛋赡石儋萏啖澹殚赕眈疸瘅聃箪\0"};
const uint8_t PY_mb_dang[] = {"当挡党荡档谠凼菪宕砀铛裆\0"};
const uint8_t PY_mb_dao[] = {"刀捣蹈倒岛祷导到稻悼道盗刂叨帱忉氘焘纛\0"};
const uint8_t PY_mb_de[] = {"德得的地锝\0"};
const uint8_t PY_mb_dei[] = {"得\0"};
const uint8_t PY_mb_deng[] = {"澄蹬灯登等瞪凳邓噔嶝戥磴镫簦\0"};
const uint8_t PY_mb_di[] = {"的抵底地蒂第帝弟递堤低滴迪敌笛狄涤翟嫡缔提氐籴诋谛邸坻荻嘀娣柢棣觌砥碲睇镝羝骶\0"};
const uint8_t PY_mb_dia[] = {"嗲\0"};
const uint8_t PY_mb_dian[] = {"电店惦点典靛奠淀殿颠掂滇碘垫佃甸阽坫巅玷钿癜癫簟踮\0"};
const uint8_t PY_mb_diao[] = {"吊刁掉钓调碉叼雕凋铞铫貂鲷\0"};
const uint8_t PY_mb_die[] = {"跌爹碟蝶迭谍叠垤堞揲喋牒瓞耋蹀鲽\0"};
const uint8_t PY_mb_ding[] = {"丁盯叮钉顶鼎锭定订仃啶玎腚碇町铤疔耵酊\0"};
const uint8_t PY_mb_diu[] = {"丢铥\0"};
const uint8_t PY_mb_dong[] = {"东冬董懂动栋侗恫冻洞咚岽峒氡胨胴硐鸫\0"};
const uint8_t PY_mb_dou[] = {"豆逗痘都兜抖斗陡蔸窦蚪篼\0"};
const uint8_t PY_mb_du[] = {"肚度渡都督毒犊独读堵睹赌杜镀妒芏嘟渎椟牍蠹笃髑黩\0"};
const uint8_t PY_mb_duan[] = {"端短锻段断缎椴煅簖\0"};
const uint8_t PY_mb_dui[] = {"堆兑队对怼憝碓\0"};
const uint8_t PY_mb_dun[] = {"盾墩吨蹲敦顿囤钝遁沌炖砘礅盹镦趸\0"};
const uint8_t PY_mb_duo[] = {"多朵度掇哆夺垛躲跺舵剁惰堕驮咄哚沲缍铎裰踱\0"};
const uint8_t PY_mb_e[] = {"阿蛾峨鹅俄额讹娥恶厄扼遏鄂饿哦噩谔垩苊莪萼呃愕屙婀轭腭锇锷鹗颚鳄\0"};
const uint8_t PY_mb_ei[] = {"诶\0"};
const uint8_t PY_mb_en[] = {"恩蒽摁\0"};
const uint8_t PY_mb_er[] = {"二而儿耳尔饵洱贰迩珥铒鸸鲕\0"};
const uint8_t PY_mb_fa[] = {"发罚筏伐乏阀法珐垡砝\0"};
const uint8_t PY_mb_fan[] = {"凡烦反返范贩犯饭泛藩帆番翻樊矾钒繁蕃蘩幡梵燔畈蹯\0"};
const uint8_t PY_mb_fang[] = {"坊芳方肪房防妨仿访纺放匚邡枋钫舫鲂\0"};
const uint8_t PY_mb_fei[] = {"菲非啡飞肥匪诽吠肺废沸费芾狒斐悱妃绯淝榧贲腓扉砩镄痱蜚篚翡霏鲱\0"};
const uint8_t PY_mb_fen[] = {"分芬奋份忿愤粪酚吩氛纷坟焚汾粉偾瀵玢棼贲鲼鼢\0"};
const uint8_t PY_mb_feng[] = {"丰封枫蜂峰锋风凤疯烽逢冯缝讽奉俸酆葑唪沣砜\0"};
const uint8_t PY_mb_fo[] = {"佛\0"};
const uint8_t PY_mb_fou[] = {"否缶\0"};
const uint8_t PY_mb_fu[] = {"复佛傅付阜父夫敷肤孵妇扶拂辐幅氟符伏俘服浮涪福袱弗甫抚辅俯釜斧脯腑府腐赴副覆赋腹负富讣附缚咐匐凫阝郛芙芾苻茯莩菔拊呋幞怫滏艴孚驸绂绋桴赙祓砩黻黼罘稃馥蚨蜉蝠蝮麸趺跗鲋鳆\0"};
const uint8_t PY_mb_ga[] = {"噶嘎夹咖伽尬尕尜旮钆\0"};
const uint8_t PY_mb_gai[] = {"该改概钙盖溉芥丐陔垓戤赅胲\0"};
const uint8_t PY_mb_gan[] = {"干甘杆柑竿肝赶感秆敢赣坩苷尴擀泔淦澉绀橄旰矸疳酐\0"};
const uint8_t PY_mb_gang[] = {"冈刚钢缸肛纲岗港杠扛戆罡筻\0"};
const uint8_t PY_mb_gao[] = {"告皋高膏篙羔糕搞镐稿睾诰郜藁缟槔槁杲锆\0"};
const uint8_t PY_mb_ge[] = {"个各盖哥骼膈歌搁戈鸽胳疙割革葛格蛤阁隔铬合咯鬲仡哿圪塥嗝纥搿铪镉袼虼舸\0"};
const uint8_t PY_mb_gei[] = {"给\0"};
const uint8_t PY_mb_gen[] = {"根跟亘茛哏艮\0"};
const uint8_t PY_mb_geng[] = {"耕更庚羹埂耿梗颈哽赓绠鲠\0"};
const uint8_t PY_mb_gong[] = {"工共攻功恭公宫弓龚供躬巩汞拱贡蚣廾珙肱觥\0"};
const uint8_t PY_mb_gou[] = {"钩勾沟苟够垢构购佝诟狗篝岣遘媾缑枸觏彀笱鞲\0"};
const uint8_t PY_mb_gu[] = {"姑估沽孤菇咕辜箍鼓古蛊骨谷股故顾固雇贾嘏诂菰崮汩梏轱牯牿臌毂瞽罟钴锢鸪鹄痼蛄酤觚鲴鹘\0"};
const uint8_t PY_mb_gua[] = {"刮瓜剐寡挂褂卦诖呱栝胍鸹\0"};
const uint8_t PY_mb_guai[] = {"乖拐怪掴\0"};
const uint8_t PY_mb_guan[] = {"关官冠观管馆罐惯灌贯纶倌莞棺掼涫盥鹳鳏\0"};
const uint8_t PY_mb_guang[] = {"光广逛咣犷桄胱\0"};
const uint8_t PY_mb_gui[] = {"瑰规圭硅归龟闺轨鬼诡桂柜跪贵刽癸炔匦刿庋宄妫桧炅晷皈簋鲑鳜\0"};
const uint8_t PY_mb_gun[] = {"辊滚棍衮绲磙鲧\0"};
const uint8_t PY_mb_guo[] = {"锅郭国果裹过涡馘埚掴呙帼崞猓椁虢锞聒蜾蝈\0"};
const uint8_t PY_mb_ha[] = {"哈蛤铪\0"};
const uint8_t PY_mb_hai[] = {"还咳孩海害氦亥骇骸嗨胲醢\0"};
const uint8_t PY_mb_han[] = {"汗汉喊寒含涵函罕酣旱憾悍焊憨邯韩翰撼鼾捍邗菡撖瀚晗焓顸颔蚶\0"};
const uint8_t PY_mb_hang[] = {"行夯杭航吭巷沆绗颃\0"};
const uint8_t PY_mb_hao[] = {"郝好耗号昊皓毫浩灏镐壕嚎豪貉蒿薅嗥嚆濠颢蚝\0"};
const uint8_t PY_mb_he[] = {"呵喝荷菏核禾和何合河盒貉阂涸赫贺褐鹤吓诃劾壑嗬阖纥曷盍颌蚵翮\0"};
const uint8_t PY_mb_hei[] = {"黑嘿\0"};
const uint8_t PY_mb_hen[] = {"痕很狠恨\0"};
const uint8_t PY_mb_heng[] = {"哼亨横衡恒蘅珩桁\0"};
const uint8_t PY_mb_hong[] = {"红轰哄烘虹鸿洪宏弘黉訇讧荭蕻薨闳泓\0"};
const uint8_t PY_mb_hou[] = {"后喉侯猴吼厚候堠後逅瘊篌糇鲎骺\0"};
const uint8_t PY_mb_hu[] = {"护互沪户核呼乎忽瑚壶葫胡蝴虎狐糊湖弧唬冱唿囫岵猢怙惚浒滹琥槲轷觳烀煳戽扈祜瓠鹄鹕鹱虍笏醐斛鹘\0"};
const uint8_t PY_mb_hua[] = {"花华猾滑哗画划化话骅桦砉铧\0"};
const uint8_t PY_mb_huai[] = {"坏槐徊怀淮踝\0"};
const uint8_t PY_mb_huan[] = {"欢环桓还缓换患唤痪焕涣宦幻鬟浣豢郇奂垸萑擐圜獾洹漶寰逭缳锾鲩\0"};
const uint8_t PY_mb_huang[] = {"晃荒慌黄磺蝗簧皇凰惶煌幌恍谎隍徨湟潢遑璜肓癀蟥篁鳇\0"};
const uint8_t PY_mb_hui[] = {"会回毁悔灰挥辉徽恢蛔慧卉惠晦贿秽烩汇讳诲绘彗溃诙茴荟蕙咴哕喙隳洄浍缋桧晖恚虺蟪麾\0"};
const uint8_t PY_mb_hun[] = {"荤昏婚魂浑混诨馄阍溷珲\0"};
const uint8_t PY_mb_huo[] = {"和豁活伙火获或惑霍货祸劐藿攉嚯夥钬锪镬耠蠖\0"};
const uint8_t PY_mb_ji[] = {"计记给技击基几脊己圾籍集及急疾汲即嫉级挤蓟既忌际冀季伎祭剂机畸稽积肌饥迹激讥鸡姬绩缉吉极棘箕辑悸济寄寂妓继纪藉奇系丌亟乩剞佶偈墼芨芰荠萁蒺蕺掎叽咭哜唧岌嵴洎彐屐骥畿玑楫殛戟戢赍觊犄齑矶羁嵇稷瘠虮笈笄暨跻跽霁鲚鲫髻麂\0"};
const uint8_t PY_mb_jia[] = {"家加嘉夹佳荚颊贾甲钾假稼价架驾嫁枷茄嘏伽郏葭岬浃迦珈戛胛恝铗铪镓痂瘕袷蛱笳袈跏\0"};
const uint8_t PY_mb_jian[] = {"建见件简健减歼荐监捡俭剪坚尖间煎兼肩艰奸缄茧检柬碱硷拣笺槛鉴践贱键箭舰剑饯渐溅涧僭谏谫谮菅蒹搛囝湔蹇謇缣枧楗戋戬牮犍毽腱睑锏鹣裥笕翦趼踺鲣鞯\0"};
const uint8_t PY_mb_jiang[] = {"讲虹僵姜将浆江疆蒋桨奖匠酱降强茳洚绛缰犟礓耩糨豇\0"};
const uint8_t PY_mb_jiao[] = {"叫较觉角校蕉椒礁焦胶交郊浇骄娇嚼搅铰矫侥脚狡饺缴绞剿教酵轿窖佼僬艽茭挢噍峤徼姣敫皎鹪蛟醮跤鲛\0"};
const uint8_t PY_mb_jie[] = {"洁结解姐戒揭杰接皆界借介捷睫秸街阶截劫节桔竭藉芥疥诫届偈讦诘卩拮喈嗟婕孑桀碣锴疖颉蚧羯鲒骱\0"};
const uint8_t PY_mb_jin[] = {"巾尽筋斤金今津紧锦仅谨进靳晋禁近烬浸劲襟卺荩堇噤馑廑妗缙瑾槿赆觐钅衿矜\0"};
const uint8_t PY_mb_jing[] = {"京惊精经井睛晶景净颈静境敬警镜径竟竞劲荆兢茎鲸粳痉靖刭儆阱陉菁獍憬泾迳弪婧肼胫腈旌靓\0"};
const uint8_t PY_mb_jiong[] = {"炯窘冂迥扃\0"};
const uint8_t PY_mb_jiu[] = {"九就救揪究纠玖韭久灸酒旧臼舅咎疚厩僦啾阄柩桕鸠鹫赳鬏\0"};
const uint8_t PY_mb_ju[] = {"巨具距俱句惧车柜剧居驹菊局咀矩举沮聚拒据踞锯炬鞠拘狙疽倨讵苣苴莒掬遽屦琚枸椐榘榉橘犋飓钜锔窭裾趄醵踽龃雎瞿鞫\0"};
const uint8_t PY_mb_juan[] = {"眷卷捐鹃娟倦绢圈鄄狷涓桊蠲锩镌隽\0"};
const uint8_t PY_mb_jue[] = {"决诀绝觉角掘倔嚼脚撅攫抉爵厥劂谲矍堀蕨噘崛獗孓珏桷橛爝镢蹶觖\0"};
const uint8_t PY_mb_jun[] = {"军君均菌钧峻俊竣浚郡骏龟捃皲筠麇\0"};
const uint8_t PY_mb_ka[] = {"卡喀咖咯佧咔胩\0"};
const uint8_t PY_mb_kai[] = {"开揩楷凯慨剀垲蒈忾恺铠锎锴\0"};
const uint8_t PY_mb_kan[] = {"看刊堪勘坎砍侃龛瞰凵莰阚槛戡\0"};
const uint8_t PY_mb_kang[] = {"康慷糠扛抗亢炕伉闶钪\0"};
const uint8_t PY_mb_kao[] = {"考靠拷烤栲犒铐尻\0"};
const uint8_t PY_mb_ke[] = {"可渴克科刻客课嗑坷苛柯棵磕颗壳咳恪蝌岢溘稞骒缂珂轲氪瞌钶铪呵锞疴窠颏蚵髁\0"};
const uint8_t PY_mb_ken[] = {"肯啃垦恳裉\0"};
const uint8_t PY_mb_keng[] = {"坑吭铿胫铒\0"};
const uint8_t PY_mb_kong[] = {"空恐孔控倥崆箜\0"};
const uint8_t PY_mb_kou[] = {"抠口扣寇芤蔻叩眍筘\0"};
const uint8_t PY_mb_ku[] = {"枯哭窟苦酷库裤绔骷刳堀喾\0"};
const uint8_t PY_mb_kua[] = {"夸垮挎跨胯侉锞\0"};
const uint8_t PY_mb_kuai[] = {"会块筷侩快蒯郐哙狯脍\0"};
const uint8_t PY_mb_kuan[] = {"宽款髋\0"};
const uint8_t PY_mb_kuang[] = {"况匡筐狂框矿眶旷诓诳邝圹夼哐纩贶\0"};
const uint8_t PY_mb_kui[] = {"亏盔岿窥葵奎魁傀馈愧溃馗匮逵睽跬夔隗蒉揆喹喟悝愦暌聩蝰篑\0"};
const uint8_t PY_mb_kun[] = {"坤昆捆困悃琨锟醌鲲阃髡\0"};
const uint8_t PY_mb_kuo[] = {"括扩廓阔蛞\0"};
const uint8_t PY_mb_la[] = {"垃拉喇蜡腊辣啦落剌邋旯砬瘌\0"};
const uint8_t PY_mb_lai[] = {"莱来赖崃徕涞濑赉睐癞籁铼\0"};
const uint8_t PY_mb_lan[] = {"蓝婪栏拦篮阑兰澜谰揽览懒缆烂滥岚漤榄斓镧褴罱\0"};
const uint8_t PY_mb_lang[] = {"郎朗浪琅榔狼廊啷阆螂锒蒗稂莨\0"};
const uint8_t PY_mb_lao[] = {"捞劳牢老佬姥酪烙涝落络唠崂醪栳铑铹痨耢\0"};
const uint8_t PY_mb_le[] = {"勒乐了仂叻泐鳓\0"};
const uint8_t PY_mb_lei[] = {"累勒雷镭蕾磊儡垒擂肋类泪羸诔嘞嫘缧檑耒酹\0"};
const uint8_t PY_mb_leng[] = {"棱楞冷塄愣\0"};
const uint8_t PY_mb_li[] = {"利力历厉立粒礼沥吏理李里厘励丽梨犁隶黎篱离漓鲤栗砾莉荔狸傈例俐痢璃哩鬲俪俚郦坜苈莅蓠藜呖唳喱猁溧澧逦娌嫠骊缡枥栎轹戾砺砬詈罹锂鹂疠疬蛎蜊蠡笠篥粝醴跞雳鲡鳢黧\0"};
const uint8_t PY_mb_lia[] = {"俩\0"};
const uint8_t PY_mb_lian[] = {"联莲连廉怜涟帘敛脸链恋炼练潋镰濂琏楝奁殓蔹臁裢裣蠊鲢\0"};
const uint8_t PY_mb_liang[] = {"两亮俩粮凉梁粱良辆量晾谅墚莨椋踉魉\0"};
const uint8_t PY_mb_liao[] = {"了撩料聊僚疗燎寥辽潦撂镣廖蓼尥嘹獠寮缭钌鹩\0"};
const uint8_t PY_mb_lie[] = {"列裂烈劣洌猎冽埒捩咧趔躐鬣\0"};
const uint8_t PY_mb_lin[] = {"临邻赁拎琳林磷霖鳞淋凛吝蔺啉嶙廪懔遴檩辚膦瞵粼躏麟\0"};
const uint8_t PY_mb_ling[] = {"令灵另棱玲菱零龄铃伶羚凌陵岭聆领酃苓呤囹泠绫柃棂瓴蛉翎鲮\0"};
const uint8_t PY_mb_liu[] = {"刘六溜琉榴硫馏留瘤流柳碌陆浏遛骝绺旒熘锍镏鹨鎏\0"};
const uint8_t PY_mb_lo[] = {"咯\0"};
const uint8_t PY_mb_long[] = {"龙弄聋咙笼窿隆垄拢陇垅茏泷珑栊胧砻癃\0"};
const uint8_t PY_mb_lou[] = {"楼娄搂篓漏陋露偻蒌喽嵝镂瘘耧蝼髅\0"};
const uint8_t PY_mb_lu[] = {"六芦卢颅庐炉掳卤虏鲁麓碌露路赂鹿潞禄录陆戮绿垆撸噜泸渌漉逯璐栌橹轳辂辘贲氇胪镥鸬鹭簏舻鲈\0"};
const uint8_t PY_mb_lv[] = {"滤率绿吕铝侣旅履屡缕虑氯律驴褛偻捋闾榈膂稆\0"};
const uint8_t PY_mb_luan[] = {"乱孪峦挛滦卵\0"};
const uint8_t PY_mb_lue[] = {"掠略锊\0"};
const uint8_t PY_mb_lun[] = {"仑抡轮伦沦纶论囵\0"};
const uint8_t PY_mb_luo[] = {"落罗铬咯烙萝螺逻锣箩骡裸洛骆络倮蠃荦捋摞猡泺漯珞椤脶硌镙瘰雒\0"};
const uint8_t PY_mb_m[] = {"呒\0"};
const uint8_t PY_mb_ma[] = {"妈麻玛码蚂马骂嘛吗摩抹唛犸嬷杩蟆\0"};
const uint8_t PY_mb_mai[] = {"埋瞒馒蛮满蔓曼慢漫谩墁幔缦熳镘颟螨鳗鞔\0"};
const uint8_t PY_mb_man[] = {"蛮馒瞒满曼谩慢漫蔓\0"};
const uint8_t PY_mb_mang[] = {"芒茫盲氓忙莽邙漭硭蟒\0"};
const uint8_t PY_mb_mao[] = {"猫茅锚毛矛髦卯茂冒帽貌贸袤铆茆峁泖瑁昴牦耄旄懋瞀蝥蟊\0"};
const uint8_t PY_mb_me[] = {"么\0"};
const uint8_t PY_mb_mei[] = {"每妹美玫枚昧寐袂魅梅酶霉煤没眉媒镁媚莓嵋猸浼湄楣镅鹛\0"};
const uint8_t PY_mb_men[] = {"门闷们扪焖懑钔\0"};
const uint8_t PY_mb_meng[] = {"萌梦蒙檬盟锰猛孟勐甍瞢懵朦礞虻蜢蠓艋艨\0"};
const uint8_t PY_mb_mi[] = {"眯醚靡糜迷谜弥米秘觅泌蜜密麋谧幂芈冖蘼咪嘧猕汨宓弭纟脒祢敉糸縻\0"};
const uint8_t PY_mb_mian[] = {"面棉眠绵冕免勉娩缅沔渑湎宀腼眄\0"};
const uint8_t PY_mb_miao[] = {"苗描瞄藐秒渺庙妙喵邈缈缪杪淼眇鹋\0"};
const uint8_t PY_mb_mie[] = {"蔑灭乜咩篾蠛\0"};
const uint8_t PY_mb_min[] = {"民抿皿敏悯闽苠岷闵泯缗玟珉愍黾鳘\0"};
const uint8_t PY_mb_ming[] = {"明螟鸣铭名命冥茗溟暝瞑酩\0"};
const uint8_t PY_mb_miu[] = {"谬缪\0"};
const uint8_t PY_mb_mo[] = {"脉没摸摹蘑模膜磨摩魔抹末莫墨默沫漠寞陌麽万谟茉蓦馍嫫殁镆秣瘼耱貊貘\0"};
const uint8_t PY_mb_mou[] = {"谋牟某侔哞缪眸蛑鍪\0"};
const uint8_t PY_mb_mu[] = {"木目睦模牟拇牡亩姆母墓暮幕募慕牧穆苜沐仫坶毪钼\0"};
const uint8_t PY_mb_na[] = {"拿哪呐钠那娜纳捺肭镎衲\0"};
const uint8_t PY_mb_nai[] = {"氖乃奶耐奈鼐佴艿萘柰\0"};
const uint8_t PY_mb_nan[] = {"南男难喃囡楠腩蝻赧\0"};
const uint8_t PY_mb_nang[] = {"囊囔馕攮曩\0"};
const uint8_t PY_mb_nao[] = {"挠脑恼闹淖孬垴呶猱瑙硇铙蛲\0"};
const uint8_t PY_mb_ne[] = {"哪呢讷\0"};
const uint8_t PY_mb_nei[] = {"内馁\0"};
const uint8_t PY_mb_nen[] = {"嫩恁\0"};
const uint8_t PY_mb_neng[] = {"能\0"};
const uint8_t PY_mb_ng[] = {"嗯\0"};
const uint8_t PY_mb_ni[] = {"你呢拟尼妮霓倪泥匿腻逆溺伲坭猊怩昵旎祢慝睨铌鲵\0"};
const uint8_t PY_mb_nian[] = {"蔫拈年碾撵捻念廿埝辇黏鲇鲶\0"};
const uint8_t PY_mb_niang[] = {"娘酿\0"};
const uint8_t PY_mb_niao[] = {"鸟尿脲袅茑嬲\0"};
const uint8_t PY_mb_nie[] = {"捏聂孽啮镊镍涅蹑蘖嗫乜陧颞臬\0"};
const uint8_t PY_mb_nin[] = {"您\0"};
const uint8_t PY_mb_ning[] = {"柠狞凝宁拧泞佞咛甯聍\0"};
const uint8_t PY_mb_niu[] = {"牛扭钮纽拗妞狃忸\0"};
const uint8_t PY_mb_nong[] = {"脓浓农弄侬哝\0"};
const uint8_t PY_mb_nou[] = {"耨\0"};
const uint8_t PY_mb_nu[] = {"奴努怒弩胬孥驽\0"};
const uint8_t PY_mb_nuan[] = {"暖\0"};
const uint8_t PY_mb_nue[] = {"疟虐\0"};
const uint8_t PY_mb_nuo[] = {"娜挪懦糯诺傩搦喏锘\0"};
const uint8_t PY_mb_nv[] = {"女恧钕衄\0"};
const uint8_t PY_mb_o[] = {"哦喔噢\0"};
const uint8_t PY_mb_ou[] = {"欧鸥殴藕呕偶沤区讴怄瓯耦\0"};
const uint8_t PY_mb_pa[] = {"扒耙啪趴爬帕怕琶葩杷筢\0"};
const uint8_t PY_mb_pai[] = {"拍排牌徘湃派迫俳蒎哌\0"};
const uint8_t PY_mb_pan[] = {"番攀潘盘磐盼畔判叛蟠蹒胖拚丬爿泮贲袢襻\0"};
const uint8_t PY_mb_pang[] = {"膀磅镑乓庞旁耪胖彷滂螃逄\0"};
const uint8_t PY_mb_pao[] = {"抛咆刨炮袍跑泡狍庖疱脬匏\0"};
const uint8_t PY_mb_pei[] = {"呸胚培裴赔陪配佩沛辔霈帔旆锫醅\0"};
const uint8_t PY_mb_pen[] = {"喷盆湓\0"};
const uint8_t PY_mb_peng[] = {"捧碰砰抨烹澎彭蓬棚硼篷膨朋鹏怦堋嘭蟛\0"};
const uint8_t PY_mb_pi[] = {"辟否坯砒霹批披劈琵毗啤脾疲皮匹痞僻丕屁譬癖貔仳陂陴邳郫圮埤鼙芘擗噼庀淠媲纰枇甓睥罴铍裨疋蚍蜱\0"};
const uint8_t PY_mb_pian[] = {"扁便篇偏片骗谝骈缏犏胼翩蹁\0"};
const uint8_t PY_mb_piao[] = {"飘漂瓢票朴剽嫖缥瞟嘌骠殍螵\0"};
const uint8_t PY_mb_pie[] = {"撇瞥丿苤氕\0"};
const uint8_t PY_mb_pin[] = {"拼频贫品聘姘嫔榀牝颦\0"};
const uint8_t PY_mb_ping[] = {"冯乒坪苹萍平凭瓶评屏俜娉枰鲆\0"};
const uint8_t PY_mb_po[] = {"泊繁坡泼颇婆破魄迫粕朴叵陂鄱珀攴攵钋钷皤笸\0"};
const uint8_t PY_mb_pou[] = {"剖裒掊\0"};
const uint8_t PY_mb_pu[] = {"普堡暴脯扑铺仆莆葡菩蒲埔朴圃浦谱曝瀑匍噗溥蹼濮璞氆镤镨\0"};
const uint8_t PY_mb_qi[] = {"稽缉期欺栖戚妻七凄漆柒沏其棋奇歧畦崎脐齐旗祈岐祁骑起岂乞企启琪琦杞契砌器气迄弃汽泣讫亟祺憩蹊鳍麒亓俟圻芑芪荠萋葺淇骐绮耆蕲桤槭欹嘁屺汔碛颀蛴蜞綦綮\0"};
const uint8_t PY_mb_qia[] = {"卡掐恰洽葜袷髂\0"};
const uint8_t PY_mb_qian[] = {"牵扦钎铅千迁签仟谦乾黔钱钳前潜遣浅谴堑嵌欠歉纤倩佥阡芊芡茜荨掮岍悭慊骞搴褰缱椠犍肷愆钤虔箝羟\0"};
const uint8_t PY_mb_qiang[] = {"枪呛腔羌墙蔷强抢跄戕戗炝锵镪丬襁嫱樯蜣羟\0"};
const uint8_t PY_mb_qiao[] = {"壳橇锹敲悄桥瞧乔侨巧鞘撬翘峭俏窍雀诮谯荞峤憔樵跷鞒缲劁愀硗铫\0"};
const uint8_t PY_mb_qie[] = {"切茄且怯窃伽惬慊妾趄郄挈锲箧\0"};
const uint8_t PY_mb_qin[] = {"钦侵亲秦琴勤芹擒禽寝沁芩揿衾吣嗪噙廑檎锓矜覃螓\0"};
const uint8_t PY_mb_qing[] = {"亲青轻氢倾卿清擎晴氰情顷请庆磬苘圊檠锖蜻罄箐綮謦鲭黥\0"};
const uint8_t PY_mb_qiong[] = {"琼穷穹蛩邛茕筇跫銎\0"};
const uint8_t PY_mb_qiu[] = {"仇龟秋丘邱球求囚酋泅俅逑裘糗遒巯犰湫楸赇虬蚯蝤鳅\0"};
const uint8_t PY_mb_qu[] = {"趋区蛆曲躯屈驱渠取娶龋趣去蛐黢戌诎劬凵苣蕖蘧岖衢阒璩觑氍朐祛磲鸲癯蠼麴瞿\0"};
const uint8_t PY_mb_quan[] = {"圈颧权醛泉全痊拳犬券劝诠荃蜷鬈犭悛绻辁畎铨筌\0"};
const uint8_t PY_mb_que[] = {"缺炔瘸却鹊榷确雀阕阙悫\0"};
const uint8_t PY_mb_qui[] = {"鼽\0"};
const uint8_t PY_mb_qun[] = {"裙群逡麇\0"};
const uint8_t PY_mb_ran[] = {"然燃冉染苒蚺髯\0"};
const uint8_t PY_mb_rang[] = {"瓤壤攘嚷让禳穰\0"};
const uint8_t PY_mb_rao[] = {"饶扰绕荛娆桡\0"};
const uint8_t PY_mb_re[] = {"惹热喏\0"};
const uint8_t PY_mb_ren[] = {"壬仁人忍韧任认刃妊纫稔亻仞荏葚饪轫衽\0"};
const uint8_t PY_mb_reng[] = {"扔仍\0"};
const uint8_t PY_mb_ri[] = {"日\0"};
const uint8_t PY_mb_rong[] = {"戎茸蓉荣融熔溶容绒冗嵘狨榕肜蝾\0"};
const uint8_t PY_mb_rou[] = {"揉柔肉糅蹂鞣\0"};
const uint8_t PY_mb_ru[] = {"茹蠕儒孺如辱乳汝入濡褥溽蓐嚅薷洳缛铷襦颥\0"};
const uint8_t PY_mb_ruan[] = {"软阮朊\0"};
const uint8_t PY_mb_rui[] = {"蕊瑞锐芮睿枘蕤蚋\0"};
const uint8_t PY_mb_run[] = {"闰润\0"};
const uint8_t PY_mb_ruo[] = {"若弱偌箬\0"};
const uint8_t PY_mb_sa[] = {"撒洒萨卅仨飒脎\0"};
const uint8_t PY_mb_sai[] = {"腮鳃塞赛噻\0"};
const uint8_t PY_mb_san[] = {"三叁伞散馓毵糁\0"};
const uint8_t PY_mb_sang[] = {"桑嗓丧搡磉颡\0"};
const uint8_t PY_mb_sao[] = {"搔骚扫嫂臊瘙埽缫鳋\0"};
const uint8_t PY_mb_se[] = {"塞瑟色涩啬铯穑\0"};
const uint8_t PY_mb_sen[] = {"森\0"};
const uint8_t PY_mb_seng[] = {"僧\0"};
const uint8_t PY_mb_sha[] = {"莎砂杀刹沙纱傻啥煞杉厦痧裟霎鲨唼歃铩\0"};
const uint8_t PY_mb_shai[] = {"色筛晒\0"};
const uint8_t PY_mb_shan[] = {"掺单珊苫杉山删煽衫闪陕擅赡膳善汕扇缮栅讪疝舢蟮跚鳝剡鄯埏芟彡潸姗嬗骟膻禅钐髟\0"};
const uint8_t PY_mb_shang[] = {"墒伤商赏晌上尚裳绱殇觞垧熵\0"};
const uint8_t PY_mb_shao[] = {"鞘梢捎稍烧芍勺韶少哨邵绍劭苕艄潲杓蛸筲\0"};
const uint8_t PY_mb_she[] = {"奢赊蛇舌舍赦摄射慑涉社设麝折厍佘揲猞滠歙畲铊\0"};
const uint8_t PY_mb_shei[] = {"谁\0"};
const uint8_t PY_mb_shen[] = {"参砷申呻伸身深娠绅神沈审婶甚肾慎渗什诜谂莘葚哂渖椹胂矧蜃\0"};
const uint8_t PY_mb_sheng[] = {"乘声生甥牲升绳省盛剩胜圣笙嵊渑晟眚\0"};
const uint8_t PY_mb_shi[] = {"是事匙师十石失狮施湿诗尸虱拾时什食蚀实识史矢使屎驶始式示士世柿拭誓逝势嗜噬适仕侍释饰氏市恃室视试似弑舐殖峙谥埘莳蓍饣轼贳炻礻铈铊螫筮酾豕鲥鲺\0"};
const uint8_t PY_mb_shou[] = {"收手首守寿授售受瘦兽扌狩绶艏\0"};
const uint8_t PY_mb_shu[] = {"蔬枢梳殊抒输叔舒淑疏书赎孰熟薯暑曙署蜀黍鼠属术述树束戍竖墅庶数漱恕倏塾沭澍姝丨菽摅纾毹腧殳镯秫疋\0"};
const uint8_t PY_mb_shua[] = {"刷耍唰\0"};
const uint8_t PY_mb_shuai[] = {"率摔衰甩帅蟀\0"};
const uint8_t PY_mb_shuan[] = {"栓拴闩涮\0"};
const uint8_t PY_mb_shuang[] = {"霜双爽泷孀\0"};
const uint8_t PY_mb_shui[] = {"水睡税说氵\0"};
const uint8_t PY_mb_shun[] = {"吮瞬顺舜\0"};
const uint8_t PY_mb_shuo[] = {"数说硕朔烁蒴搠妁槊铄\0"};
const uint8_t PY_mb_si[] = {"斯撕嘶思私司丝死肆寺嗣四伺似饲巳厮咝俟兕厶饣汜泗澌姒驷缌祀锶鸶耜蛳笥\0"};
const uint8_t PY_mb_song[] = {"松耸怂颂送宋讼诵嵩忪悚淞竦崧菘凇\0"};
const uint8_t PY_mb_sou[] = {"搜艘擞嗽叟嗖馊溲飕瞍锼螋嗾薮\0"};
const uint8_t PY_mb_su[] = {"苏酥俗素速粟僳塑溯宿诉肃缩夙愫涑簌稣谡蔌嗉觫\0"};
const uint8_t PY_mb_suan[] = {"酸蒜算狻\0"};
const uint8_t PY_mb_sui[] = {"虽岁绥隋随髓祟遂碎隧穗\0"};
const uint8_t PY_mb_sun[] = {"孙损笋\0"};
const uint8_t PY_mb_suo[] = {"蓑梭唆缩琐索锁所唢嗦嗍娑莎桫挲睃羧\0"};
const uint8_t PY_mb_ta[] = {"塌他它她塔獭挞沓蹋踏拓闼遢榻铊趿溻鳎漯\0"};
const uint8_t PY_mb_tai[] = {"胎苔抬台泰酞太态汰跆邰薹骀肽炱钛鲐\0"};
const uint8_t PY_mb_tan[] = {"弹坍摊贪瘫滩坛檀痰潭谭谈坦毯袒碳探叹炭覃郯澹昙赕忐钽锬镡\0"};
const uint8_t PY_mb_tang[] = {"汤塘搪堂棠膛唐糖倘躺淌趟烫傥饧溏瑭樘铛螳铴镗耥螗羰醣帑\0"};
const uint8_t PY_mb_tao[] = {"掏涛滔绦萄桃逃淘陶讨套叨啕饕洮韬焘鼗\0"};
const uint8_t PY_mb_te[] = {"特忒忑铽\0"};
const uint8_t PY_mb_teng[] = {"藤腾疼滕誊\0"};
const uint8_t PY_mb_ti[] = {"梯剔踢锑提题蹄啼体替嚏惕涕剃屉倜悌缇荑逖绨鹈裼醍\0"};
const uint8_t PY_mb_tian[] = {"天添填田甜恬舔腆殄掭忝阗畋钿锘\0"};
const uint8_t PY_mb_tiao[] = {"调挑条迢眺跳佻髫苕祧铫窕蜩笤粜龆鲦\0"};
const uint8_t PY_mb_tie[] = {"贴铁帖餮锇萜\0"};
const uint8_t PY_mb_ting[] = {"厅听烃汀廷停亭庭挺艇莛葶婷铤蜓霆梃\0"};
const uint8_t PY_mb_tong[] = {"桐瞳同铜彤童桶捅筒统痛佟僮茼恸潼酮仝垌嗵峒砼\0"};
const uint8_t PY_mb_tou[] = {"偷投头透骰钭亠\0"};
const uint8_t PY_mb_tu[] = {"凸秃突图徒途涂屠土吐兔堍荼菟钍酴\0"};
const uint8_t PY_mb_tuan[] = {"湍团抟彖疃\0"};
const uint8_t PY_mb_tui[] = {"推颓腿蜕褪退煺\0"};
const uint8_t PY_mb_tun[] = {"囤褪吞屯臀饨豚氽暾\0"};
const uint8_t PY_mb_tuo[] = {"说拖拓托脱鸵陀驮驼椭妥唾跎乇佗坨沱柝柁橐砣铊鼍箨酡庹\0"};
const uint8_t PY_mb_wa[] = {"挖哇蛙洼娃瓦袜佤娲腽\0"};
const uint8_t PY_mb_wai[] = {"歪外崴\0"};
const uint8_t PY_mb_wan[] = {"蔓豌弯湾玩顽丸烷完碗挽晚皖惋宛婉万腕剜芄莞菀纨蜿绾琬脘畹鞔\0"};
const uint8_t PY_mb_wang[] = {"汪王亡枉网往旺望忘妄罔惘魍尢辋\0"};
const uint8_t PY_mb_wei[] = {"为位谓威巍微危韦维违桅围唯惟潍苇萎委伟伪尾纬未蔚味畏胃喂魏渭尉慰卫偎诿隗圩葳薇帏帷崴嵬猬逶娓痿炜玮闱猥隈沩洧涠韪軎煨艉鲔囗\0"};
const uint8_t PY_mb_wen[] = {"问文闻纹瘟温蚊吻稳紊刎雯玟阌汶璺\0"};
const uint8_t PY_mb_weng[] = {"嗡翁瓮蓊蕹\0"};
const uint8_t PY_mb_wo[] = {"我握喔蜗涡窝斡卧沃挝倭莴幄龌渥肟硪\0"};
const uint8_t PY_mb_wu[] = {"五物勿务午舞伍武侮恶悟误兀巫雾呜钨乌污诬屋无芜梧吾吴毋捂坞戊晤仵邬鹉圬芴唔庑怃忤鹜痦蜈浯寤迕妩婺骛阢杌牾於焐鋈鼯\0"};
const uint8_t PY_mb_xi[] = {"希习夕戏细昔熙析西硒矽晰嘻吸锡牺稀蹊息悉膝惜熄溪汐犀袭席媳喜洗系隙羲皙屣嬉玺樨奚茜檄烯铣匚僖兮隰郗菥葸蓰唏徙饩阋浠淅曦觋欷歙熹禊禧穸裼蜥螅蟋舄舾粞翕醯鼷\0"};
const uint8_t PY_mb_xia[] = {"瞎虾匣霞辖暇峡侠狭下厦夏吓呷狎遐瑕柙硖罅黠\0"};
const uint8_t PY_mb_xian[] = {"现先仙嫌显险献县贤铣洗掀锨鲜纤咸衔舷闲涎弦腺馅羡宪陷限线冼苋莶藓岘猃暹娴氙燹祆鹇痃痫蚬筅籼酰跣跹霰\0"};
const uint8_t PY_mb_xiang[] = {"像向象降相厢镶香箱湘乡翔祥详想响享项巷橡襄飨芗葙饷庠骧缃蟓鲞\0"};
const uint8_t PY_mb_xiao[] = {"小消肖萧硝霄削哮嚣销宵淆晓孝校啸笑效哓潇逍筱箫骁绡枭枵蛸魈\0"};
const uint8_t PY_mb_xie[] = {"些歇蝎鞋协挟携邪斜胁谐写械卸蟹懈泄泻谢屑血解楔叶偕亵勰燮薤撷獬廨渫瀣邂绁缬榭榍颉躞鲑骱\0"};
const uint8_t PY_mb_xin[] = {"薪芯锌欣辛新忻心信衅馨莘歆鑫昕囟忄镡\0"};
const uint8_t PY_mb_xing[] = {"幸省星腥猩惺兴刑型形邢行醒杏性姓饧陉荇荥擤悻硎\0"};
const uint8_t PY_mb_xiong[] = {"兄凶胸匈汹雄熊芎\0"};
const uint8_t PY_mb_xiu[] = {"臭宿休修羞朽嗅锈秀袖绣咻溴貅馐岫庥鸺髹\0"};
const uint8_t PY_mb_xu[] = {"续绪墟戌需虚嘘须徐许蓄酗叙旭序畜恤絮婿诩煦勖圩蓿洫浒溆顼栩吁胥盱糈醑\0"};
const uint8_t PY_mb_xuan[] = {"玄选轩喧宣渲悬旋暄绚炫眩癣儇谖萱泫漩璇楦煊揎碹铉镟券\0"};
const uint8_t PY_mb_xue[] = {"削靴薛学穴雪血鳕谑噱泶踅\0"};
const uint8_t PY_mb_xun[] = {"寻旬迅讯询训勋熏循驯巡殉汛逊郇埙荀薰峋徇醺鲟浚荨蕈獯巽恂洵浔曛窨\0"};
const uint8_t PY_mb_ya[] = {"牙芽亚哑压雅押鸦鸭呀丫崖衙涯讶轧伢蚜垭揠岈迓娅琊桠氩砑睚痖疋\0"};
const uint8_t PY_mb_yan[] = {"言演验厌严沿炎燕咽阉奄掩眼烟淹盐研岩延颜阎衍艳堰砚雁唁焉彦焰宴谚蜒闫妍嫣胭腌焱恹俨偃铅殷厣赝剡兖讠谳阽郾鄢芫菸崦魇阏湮滟琰檐晏罨筵酽餍鼹鼽\0"};
const uint8_t PY_mb_yang[] = {"央仰羊洋阳养样杨扬恙殃鸯秧佯氧疡痒漾徉怏泱炀烊蛘鞅\0"};
const uint8_t PY_mb_yao[] = {"要邀咬药腰妖摇尧肴窈遥窑谣姚舀耀钥夭爻幺吆瑶啮疟侥崤崾徭珧杳轺曜铫鹞繇鳐\0"};
const uint8_t PY_mb_ye[] = {"也页业叶夜液椰噎耶爷野冶掖曳腋邪咽谒盅靥邺揶琊晔烨铘\0"};
const uint8_t PY_mb_yi[] = {"一乙已以忆义议谊译异益壹医揖铱依伊衣颐夷遗移仪胰疑沂宜姨彝椅蚁倚矣艺抑易邑屹亿役臆逸肄疫亦裔意毅溢诣翼翌艾尾绎刈劓佚佾诒阝圯埸懿苡荑薏弈奕挹弋呓咦咿噫峄嶷猗饴怿怡悒漪迤驿缢殪轶贻欹旖熠眙钇铊镒镱痍瘗癔翊衤蜴舣羿翳酏黟\0"};
const uint8_t PY_mb_yin[] = {"尹引印茵荫因殷音阴姻吟银淫寅饮隐龈胤蚓鄞廴垠堙茚吲喑狺夤洇湮氤铟瘾窨霪\0"};
const uint8_t PY_mb_ying[] = {"映影英莹萤营荧樱婴鹰应缨蝇迎赢盈颖硬嬴莺萦鹦潆瀛滢瑛郢茔荥蓥撄嘤膺璎楹媵瘿颍罂\0"};
const uint8_t PY_mb_yo[] = {"哟育唷\0"};
const uint8_t PY_mb_yong[] = {"用拥佣勇涌臃痈庸雍踊蛹咏泳永恿俑壅墉喁慵邕镛甬鳙饔\0"};
const uint8_t PY_mb_you[] = {"尤有又诱幼友右佑幽优悠忧由邮铀犹油游酉釉呦疣鱿黝鼬蚰攸卣侑莠莜莸尢囿宥柚猷牖铕蚴蝣蝤繇\0"};
const uint8_t PY_mb_yu[] = {"余与于予宇玉雨育誉浴鱼迂淤盂虞愚舆俞逾愉渝渔隅娱屿禹语羽域芋郁吁遇喻峪御愈榆欲狱寓裕预豫驭竽毓谀於谕蔚尉禺伛俣萸菀蓣揄圄圉嵛狳饫馀庾阈鬻妪妤纡瑜昱觎腴欤煜熨燠肀聿钰鹆鹬瘐瘀窬窳蜮蝓臾舁雩龉\0"};
const uint8_t PY_mb_yuan[] = {"原元园员圆源缘远愿怨院鸳渊冤垣袁援辕猿苑媛塬芫掾圜沅瑗橼爰眢鸢螈箢鼋\0"};
const uint8_t PY_mb_yue[] = {"月悦阅乐说曰约越跃钥岳粤龠哕瀹栎樾刖钺\0"};
const uint8_t PY_mb_yun[] = {"云员允运晕耘匀陨蕴酝熨韵孕氲殒芸郧郓狁恽愠纭韫昀筠\0"};
const uint8_t PY_mb_za[] = {"匝砸杂扎咋咂拶\0"};
const uint8_t PY_mb_zai[] = {"再在栽哉灾宰载崽甾\0"};
const uint8_t PY_mb_zan[] = {"咱攒暂赞昝簪拶瓒糌趱錾\0"};
const uint8_t PY_mb_zang[] = {"藏赃脏葬驵臧\0"};
const uint8_t PY_mb_zao[] = {"枣遭早造皂灶糟凿澡躁噪燥藻蚤唣\0"};
const uint8_t PY_mb_ze[] = {"责择则泽咋仄赜啧帻迮昃笮箦舴\0"};
const uint8_t PY_mb_zei[] = {"贼\0"};
const uint8_t PY_mb_zen[] = {"怎谮\0"};
const uint8_t PY_mb_zeng[] = {"增憎曾赠缯甑罾锃\0"};
const uint8_t PY_mb_zha[] = {"扎闸查喳渣札轧铡眨栅榨咋乍炸诈吒咤柞揸蚱哳喋楂砟痄龃齄\0"};
const uint8_t PY_mb_zhai[] = {"宅窄债翟择摘斋寨砦瘵\0"};
const uint8_t PY_mb_zhan[] = {"占战站展沾绽瞻毡詹粘盏斩辗崭蘸颤栈湛谵搌骣旃\0"};
const uint8_t PY_mb_zhang[] = {"张丈仗胀杖樟章彰漳掌涨帐账长瘴障幛嶂獐蟑仉鄣嫜璋\0"};
const uint8_t PY_mb_zhao[] = {"找召爪着兆朝招昭诏沼赵照罩肇钊笊啁棹\0"};
const uint8_t PY_mb_zhe[] = {"遮折哲蛰辙者锗蔗这浙着谪摺柘辄磔鹧褶蜇赭\0"};
const uint8_t PY_mb_zhen[] = {"真贞针震振诊阵镇侦枕珍疹斟甄箴臻帧圳砧蓁浈溱缜桢椹榛轸赈胗朕祯畛稹鸩\0"};
const uint8_t PY_mb_zheng[] = {"正证蒸挣睁征狰争怔整拯政症郑诤峥徵钲铮筝鲭\0"};
const uint8_t PY_mb_zhi[] = {"质置制治支只识执值止至芝之汁旨纸志枝知肢脂织职直植殖侄址指趾挚掷致帜峙智秩稚吱蜘炙痔滞窒枳芷卮陟郅埴摭帙徵夂忮彘咫骘栉栀桎轵轾贽胝膣祉祗黹雉鸷痣蛭絷酯跖踬踯豸觯\0"};
const uint8_t PY_mb_zhong[] = {"中众忠钟衷终种肿重仲盅冢忪锺螽舯踵\0"};
const uint8_t PY_mb_zhou[] = {"舟周州洲诌粥轴肘帚咒皱宙昼骤荮啁妯纣绉胄碡籀繇酎\0"};
const uint8_t PY_mb_zhu[] = {"主住注祝竹珠株蛛朱猪诸诛逐烛煮拄瞩嘱著柱助蛀贮铸筑驻伫竺箸侏属术邾苎茱洙渚潴杼槠橥炷铢疰瘃褚舳翥躅麈丶\0"};
const uint8_t PY_mb_zhua[] = {"抓爪挝\0"};
const uint8_t PY_mb_zhuai[] = {"拽转\0"};
const uint8_t PY_mb_zhuan[] = {"传专砖转撰赚篆啭馔沌颛\0"};
const uint8_t PY_mb_zhuang[] = {"幢桩庄装妆撞壮状奘戆\0"};
const uint8_t PY_mb_zhui[] = {"椎锥追赘坠缀惴骓缒隹\0"};
const uint8_t PY_mb_zhun[] = {"谆准饨肫窀\0"};
const uint8_t PY_mb_zhuo[] = {"着捉拙卓桌灼茁浊酌琢啄倬诼擢浞涿濯焯禚斫镯\0"};
const uint8_t PY_mb_zi[] = {"自子字仔兹咨资姿滋淄孜紫籽滓渍龇姊吱嵫谘茈孳缁梓辎赀恣眦锱秭耔笫粢趑觜訾鲻髭\0"};
const uint8_t PY_mb_zong[] = {"宗综总鬃棕踪纵粽偬枞腙\0"};
const uint8_t PY_mb_zou[] = {"走奏揍邹诹陬鄹驺鲰\0"};
const uint8_t PY_mb_zu[] = {"足租祖诅阻组卒族俎菹镞\0"};
const uint8_t PY_mb_zuan[] = {"钻攥纂缵躜\0"};
const uint8_t PY_mb_zui[] = {"最罪嘴醉蕞觜\0"};
const uint8_t PY_mb_zun[] = {"尊遵樽鳟撙\0"};
const uint8_t PY_mb_zuo[] = {"左佐做作坐座昨撮唑柞阼琢嘬怍胙祚砟酢\0"};

// 拼音索引表
const py_index py_index3[] =
    {
        {"", "", (uint8_t *)PY_mb_space},
        {"2", "a", (uint8_t *)PY_mb_a},
        {"3", "e", (uint8_t *)PY_mb_e},
        {"6", "o", (uint8_t *)PY_mb_o},
        {"24", "ai", (uint8_t *)PY_mb_ai},
        {"26", "an", (uint8_t *)PY_mb_an},
        {"26", "ao", (uint8_t *)PY_mb_ao},
        {"22", "ba", (uint8_t *)PY_mb_ba},
        {"24", "bi", (uint8_t *)PY_mb_bi},
        {"26", "bo", (uint8_t *)PY_mb_bo},
        {"28", "bu", (uint8_t *)PY_mb_bu},
        {"22", "ca", (uint8_t *)PY_mb_ca},
        {"23", "ce", (uint8_t *)PY_mb_ce},
        {"24", "ci", (uint8_t *)PY_mb_ci},
        {"28", "cu", (uint8_t *)PY_mb_cu},
        {"32", "da", (uint8_t *)PY_mb_da},
        {"33", "de", (uint8_t *)PY_mb_de},
        {"34", "di", (uint8_t *)PY_mb_di},
        {"38", "du", (uint8_t *)PY_mb_du},
        {"36", "en", (uint8_t *)PY_mb_en},
        {"37", "er", (uint8_t *)PY_mb_er},
        {"32", "fa", (uint8_t *)PY_mb_fa},
        {"36", "fo", (uint8_t *)PY_mb_fo},
        {"38", "fu", (uint8_t *)PY_mb_fu},
        {"42", "ha", (uint8_t *)PY_mb_ha},
        {"42", "ga", (uint8_t *)PY_mb_ga},
        {"43", "ge", (uint8_t *)PY_mb_ge},
        {"43", "he", (uint8_t *)PY_mb_he},
        {"48", "gu", (uint8_t *)PY_mb_gu},
        {"48", "hu", (uint8_t *)PY_mb_hu},
        {"54", "ji", (uint8_t *)PY_mb_ji},
        {"58", "ju", (uint8_t *)PY_mb_ju},
        {"52", "ka", (uint8_t *)PY_mb_ka},
        {"53", "ke", (uint8_t *)PY_mb_ke},
        {"58", "ku", (uint8_t *)PY_mb_ku},
        {"52", "la", (uint8_t *)PY_mb_la},
        {"53", "le", (uint8_t *)PY_mb_le},
        {"54", "li", (uint8_t *)PY_mb_li},
        {"58", "lu", (uint8_t *)PY_mb_lu},
        {"58", "lv", (uint8_t *)PY_mb_lv},
        {"62", "ma", (uint8_t *)PY_mb_ma},
        {"63", "me", (uint8_t *)PY_mb_me},
        {"64", "mi", (uint8_t *)PY_mb_mi},
        {"66", "mo", (uint8_t *)PY_mb_mo},
        {"68", "mu", (uint8_t *)PY_mb_mu},
        {"62", "na", (uint8_t *)PY_mb_na},
        {"63", "ne", (uint8_t *)PY_mb_ne},
        {"64", "ni", (uint8_t *)PY_mb_ni},
        {"68", "nu", (uint8_t *)PY_mb_nu},
        {"68", "nv", (uint8_t *)PY_mb_nv},
        {"68", "ou", (uint8_t *)PY_mb_ou},
        {"72", "pa", (uint8_t *)PY_mb_pa},
        {"74", "pi", (uint8_t *)PY_mb_pi},
        {"76", "po", (uint8_t *)PY_mb_po},
        {"78", "pu", (uint8_t *)PY_mb_pu},
        {"74", "qi", (uint8_t *)PY_mb_qi},
        {"78", "qu", (uint8_t *)PY_mb_qu},
        {"73", "re", (uint8_t *)PY_mb_re},
        {"74", "ri", (uint8_t *)PY_mb_ri},
        {"78", "ru", (uint8_t *)PY_mb_ru},
        {"72", "sa", (uint8_t *)PY_mb_sa},
        {"73", "se", (uint8_t *)PY_mb_se},
        {"74", "si", (uint8_t *)PY_mb_si},
        {"78", "su", (uint8_t *)PY_mb_su},
        {"82", "ta", (uint8_t *)PY_mb_ta},
        {"83", "te", (uint8_t *)PY_mb_te},
        {"84", "ti", (uint8_t *)PY_mb_ti},
        {"88", "tu", (uint8_t *)PY_mb_tu},
        {"92", "wa", (uint8_t *)PY_mb_wa},
        {"96", "wo", (uint8_t *)PY_mb_wo},
        {"98", "wu", (uint8_t *)PY_mb_wu},
        {"94", "xi", (uint8_t *)PY_mb_xi},
        {"98", "xu", (uint8_t *)PY_mb_xu},
        {"92", "ya", (uint8_t *)PY_mb_ya},
        {"93", "ye", (uint8_t *)PY_mb_ye},
        {"94", "yi", (uint8_t *)PY_mb_yi},
        {"96", "yo", (uint8_t *)PY_mb_yo},
        {"98", "yu", (uint8_t *)PY_mb_yu},
        {"92", "za", (uint8_t *)PY_mb_za},
        {"93", "ze", (uint8_t *)PY_mb_ze},
        {"94", "zi", (uint8_t *)PY_mb_zi},
        {"98", "zu", (uint8_t *)PY_mb_zu},
        {"264", "ang", (uint8_t *)PY_mb_ang},
        {"224", "bai", (uint8_t *)PY_mb_bai},
        {"226", "ban", (uint8_t *)PY_mb_ban},
        {"226", "bao", (uint8_t *)PY_mb_bao},
        {"234", "bei", (uint8_t *)PY_mb_bei},
        {"236", "ben", (uint8_t *)PY_mb_ben},
        {"243", "bie", (uint8_t *)PY_mb_bie},
        {"246", "bin", (uint8_t *)PY_mb_bin},
        {"224", "cai", (uint8_t *)PY_mb_cai},
        {"226", "can", (uint8_t *)PY_mb_can},
        {"226", "cao", (uint8_t *)PY_mb_cao},
        {"242", "cha", (uint8_t *)PY_mb_cha},
        {"243", "che", (uint8_t *)PY_mb_che},
        {"244", "chi", (uint8_t *)PY_mb_chi},
        {"248", "chu", (uint8_t *)PY_mb_chu},
        {"268", "cou", (uint8_t *)PY_mb_cou},
        {"284", "cui", (uint8_t *)PY_mb_cui},
        {"286", "cun", (uint8_t *)PY_mb_cun},
        {"286", "cuo", (uint8_t *)PY_mb_cuo},
        {"324", "dai", (uint8_t *)PY_mb_dai},
        {"326", "dan", (uint8_t *)PY_mb_dan},
        {"326", "dao", (uint8_t *)PY_mb_dao},
        {"334", "dei", (uint8_t *)PY_mb_dei},
        {"343", "die", (uint8_t *)PY_mb_die},
        {"348", "diu", (uint8_t *)PY_mb_diu},
        {"368", "dou", (uint8_t *)PY_mb_dou},
        {"384", "dui", (uint8_t *)PY_mb_dui},
        {"386", "dun", (uint8_t *)PY_mb_dun},
        {"386", "duo", (uint8_t *)PY_mb_duo},
        {"326", "fan", (uint8_t *)PY_mb_fan},
        {"334", "fei", (uint8_t *)PY_mb_fei},
        {"336", "fen", (uint8_t *)PY_mb_fen},
        {"368", "fou", (uint8_t *)PY_mb_fou},
        {"424", "gai", (uint8_t *)PY_mb_gai},
        {"426", "gan", (uint8_t *)PY_mb_gan},
        {"426", "gao", (uint8_t *)PY_mb_gao},
        {"434", "gei", (uint8_t *)PY_mb_gei},
        {"436", "gen", (uint8_t *)PY_mb_gan},
        {"468", "gou", (uint8_t *)PY_mb_gou},
        {"482", "gua", (uint8_t *)PY_mb_gua},
        {"484", "gui", (uint8_t *)PY_mb_gui},
        {"486", "gun", (uint8_t *)PY_mb_gun},
        {"486", "guo", (uint8_t *)PY_mb_guo},
        {"424", "hai", (uint8_t *)PY_mb_hai},
        {"426", "han", (uint8_t *)PY_mb_han},
        {"426", "hao", (uint8_t *)PY_mb_hao},
        {"434", "hei", (uint8_t *)PY_mb_hei},
        {"436", "hen", (uint8_t *)PY_mb_hen},
        {"468", "hou", (uint8_t *)PY_mb_hou},
        {"482", "hua", (uint8_t *)PY_mb_hua},
        {"484", "hui", (uint8_t *)PY_mb_hui},
        {"486", "hun", (uint8_t *)PY_mb_hun},
        {"486", "huo", (uint8_t *)PY_mb_huo},
        {"542", "jia", (uint8_t *)PY_mb_jia},
        {"543", "jie", (uint8_t *)PY_mb_jie},
        {"546", "jin", (uint8_t *)PY_mb_jin},
        {"548", "jiu", (uint8_t *)PY_mb_jiu},
        {"583", "jue", (uint8_t *)PY_mb_jue},
        {"586", "jun", (uint8_t *)PY_mb_jun},
        {"524", "kai", (uint8_t *)PY_mb_kai},
        {"526", "kan", (uint8_t *)PY_mb_kan},
        {"526", "kao", (uint8_t *)PY_mb_kao},
        {"536", "ken", (uint8_t *)PY_mb_ken},
        {"568", "kou", (uint8_t *)PY_mb_kou},
        {"582", "kua", (uint8_t *)PY_mb_kua},
        {"584", "kui", (uint8_t *)PY_mb_kui},
        {"586", "kun", (uint8_t *)PY_mb_kun},
        {"586", "kuo", (uint8_t *)PY_mb_kuo},
        {"524", "lai", (uint8_t *)PY_mb_lai},
        {"526", "lan", (uint8_t *)PY_mb_lan},
        {"526", "lao", (uint8_t *)PY_mb_lao},
        {"534", "lei", (uint8_t *)PY_mb_lei},
        {"543", "lie", (uint8_t *)PY_mb_lie},
        {"546", "lin", (uint8_t *)PY_mb_lin},
        {"548", "liu", (uint8_t *)PY_mb_liu},
        {"568", "lou", (uint8_t *)PY_mb_lou},
        {"583", "lue", (uint8_t *)PY_mb_lue},
        {"586", "lun", (uint8_t *)PY_mb_lun},
        {"586", "luo", (uint8_t *)PY_mb_luo},
        {"624", "mai", (uint8_t *)PY_mb_mai},
        {"626", "man", (uint8_t *)PY_mb_man},
        {"626", "mao", (uint8_t *)PY_mb_mao},
        {"634", "mei", (uint8_t *)PY_mb_mei},
        {"636", "men", (uint8_t *)PY_mb_men},
        {"643", "mie", (uint8_t *)PY_mb_mie},
        {"646", "min", (uint8_t *)PY_mb_min},
        {"648", "miu", (uint8_t *)PY_mb_miu},
        {"668", "mou", (uint8_t *)PY_mb_mou},
        {"624", "nai", (uint8_t *)PY_mb_nai},
        {"626", "nan", (uint8_t *)PY_mb_nan},
        {"626", "nao", (uint8_t *)PY_mb_nao},
        {"634", "nei", (uint8_t *)PY_mb_nei},
        {"636", "nen", (uint8_t *)PY_mb_nen},
        {"643", "nie", (uint8_t *)PY_mb_nie},
        {"646", "nin", (uint8_t *)PY_mb_nin},
        {"648", "niu", (uint8_t *)PY_mb_niu},
        {"683", "nue", (uint8_t *)PY_mb_nue},
        {"686", "nuo", (uint8_t *)PY_mb_nuo},
        {"724", "pai", (uint8_t *)PY_mb_pai},
        {"726", "pan", (uint8_t *)PY_mb_pan},
        {"726", "pao", (uint8_t *)PY_mb_pao},
        {"734", "pei", (uint8_t *)PY_mb_pei},
        {"736", "pen", (uint8_t *)PY_mb_pen},
        {"743", "pie", (uint8_t *)PY_mb_pie},
        {"746", "pin", (uint8_t *)PY_mb_pin},
        {"768", "pou", (uint8_t *)PY_mb_pou},
        {"742", "qia", (uint8_t *)PY_mb_qia},
        {"743", "qie", (uint8_t *)PY_mb_qie},
        {"746", "qin", (uint8_t *)PY_mb_qin},
        {"748", "qiu", (uint8_t *)PY_mb_qiu},
        {"783", "que", (uint8_t *)PY_mb_que},
        {"786", "qun", (uint8_t *)PY_mb_qun},
        {"726", "ran", (uint8_t *)PY_mb_ran},
        {"726", "rao", (uint8_t *)PY_mb_rao},
        {"736", "ren", (uint8_t *)PY_mb_ren},
        {"768", "rou", (uint8_t *)PY_mb_rou},
        {"784", "rui", (uint8_t *)PY_mb_rui},
        {"786", "run", (uint8_t *)PY_mb_run},
        {"786", "ruo", (uint8_t *)PY_mb_ruo},
        {"724", "sai", (uint8_t *)PY_mb_sai},
        {"726", "sao", (uint8_t *)PY_mb_sao},
        {"726", "san", (uint8_t *)PY_mb_san},
        {"736", "sen", (uint8_t *)PY_mb_sen},
        {"742", "sha", (uint8_t *)PY_mb_sha},
        {"743", "she", (uint8_t *)PY_mb_she},
        {"744", "shi", (uint8_t *)PY_mb_shi},
        {"748", "shu", (uint8_t *)PY_mb_shu},
        {"768", "sou", (uint8_t *)PY_mb_sou},
        {"784", "sui", (uint8_t *)PY_mb_sui},
        {"786", "sun", (uint8_t *)PY_mb_sun},
        {"786", "suo", (uint8_t *)PY_mb_suo},
        {"824", "tai", (uint8_t *)PY_mb_tai},
        {"826", "tan", (uint8_t *)PY_mb_tan},
        {"826", "tao", (uint8_t *)PY_mb_tao},
        {"843", "tie", (uint8_t *)PY_mb_tie},
        {"868", "tou", (uint8_t *)PY_mb_tou},
        {"884", "tui", (uint8_t *)PY_mb_tui},
        {"886", "tun", (uint8_t *)PY_mb_tun},
        {"886", "tuo", (uint8_t *)PY_mb_tuo},
        {"924", "wai", (uint8_t *)PY_mb_wai},
        {"926", "wan", (uint8_t *)PY_mb_wan},
        {"934", "wei", (uint8_t *)PY_mb_wei},
        {"936", "wen", (uint8_t *)PY_mb_wen},
        {"942", "xia", (uint8_t *)PY_mb_xia},
        {"943", "xie", (uint8_t *)PY_mb_xie},
        {"946", "xin", (uint8_t *)PY_mb_xin},
        {"948", "xiu", (uint8_t *)PY_mb_xiu},
        {"983", "xue", (uint8_t *)PY_mb_xue},
        {"986", "xun", (uint8_t *)PY_mb_xun},
        {"926", "yan", (uint8_t *)PY_mb_yan},
        {"926", "yao", (uint8_t *)PY_mb_yao},
        {"946", "yin", (uint8_t *)PY_mb_yin},
        {"968", "you", (uint8_t *)PY_mb_you},
        {"983", "yue", (uint8_t *)PY_mb_yue},
        {"986", "yun", (uint8_t *)PY_mb_yun},
        {"924", "zai", (uint8_t *)PY_mb_zai},
        {"926", "zan", (uint8_t *)PY_mb_zan},
        {"926", "zao", (uint8_t *)PY_mb_zao},
        {"934", "zei", (uint8_t *)PY_mb_zei},
        {"936", "zen", (uint8_t *)PY_mb_zen},
        {"942", "zha", (uint8_t *)PY_mb_zha},
        {"943", "zhe", (uint8_t *)PY_mb_zhe},
        {"944", "zhi", (uint8_t *)PY_mb_zhi},
        {"948", "zhu", (uint8_t *)PY_mb_zhu},
        {"968", "zou", (uint8_t *)PY_mb_zou},
        {"984", "zui", (uint8_t *)PY_mb_zui},
        {"986", "zun", (uint8_t *)PY_mb_zun},
        {"986", "zuo", (uint8_t *)PY_mb_zuo},
        {"2264", "bang", (uint8_t *)PY_mb_bang},
        {"2364", "beng", (uint8_t *)PY_mb_beng},
        {"2426", "bian", (uint8_t *)PY_mb_bian},
        {"2426", "biao", (uint8_t *)PY_mb_biao},
        {"2464", "bing", (uint8_t *)PY_mb_bing},
        {"2264", "cang", (uint8_t *)PY_mb_cang},
        {"2364", "ceng", (uint8_t *)PY_mb_ceng},
        {"2424", "chai", (uint8_t *)PY_mb_chai},
        {"2426", "chan", (uint8_t *)PY_mb_chan},
        {"2426", "chao", (uint8_t *)PY_mb_chao},
        {"2436", "chen", (uint8_t *)PY_mb_chen},
        {"2468", "chou", (uint8_t *)PY_mb_chou},
        {"2484", "chuai", (uint8_t *)PY_mb_chuai},
        {"2484", "chui", (uint8_t *)PY_mb_chui},
        {"2486", "chun", (uint8_t *)PY_mb_chun},
        {"2486", "chuo", (uint8_t *)PY_mb_chuo},
        {"2664", "cong", (uint8_t *)PY_mb_cong},
        {"2826", "cuan", (uint8_t *)PY_mb_cuan},
        {"3264", "dang", (uint8_t *)PY_mb_dang},
        {"3364", "deng", (uint8_t *)PY_mb_deng},
        {"3426", "dian", (uint8_t *)PY_mb_dian},
        {"3426", "diao", (uint8_t *)PY_mb_diao},
        {"3464", "ding", (uint8_t *)PY_mb_ding},
        {"3664", "dong", (uint8_t *)PY_mb_dong},
        {"3826", "duan", (uint8_t *)PY_mb_duan},
        {"3264", "fang", (uint8_t *)PY_mb_fang},
        {"3364", "feng", (uint8_t *)PY_mb_feng},
        {"4264", "gang", (uint8_t *)PY_mb_gang},
        {"4364", "geng", (uint8_t *)PY_mb_geng},
        {"4664", "gong", (uint8_t *)PY_mb_gong},
        {"4824", "guai", (uint8_t *)PY_mb_guai},
        {"4826", "guan", (uint8_t *)PY_mb_guan},
        {"4264", "hang", (uint8_t *)PY_mb_hang},
        {"4364", "heng", (uint8_t *)PY_mb_heng},
        {"4664", "hong", (uint8_t *)PY_mb_hong},
        {"4823", "huai", (uint8_t *)PY_mb_huai},
        {"4826", "huan", (uint8_t *)PY_mb_huan},
        {"5426", "jian", (uint8_t *)PY_mb_jian},
        {"5426", "jiao", (uint8_t *)PY_mb_jiao},
        {"5464", "jing", (uint8_t *)PY_mb_jing},
        {"5826", "juan", (uint8_t *)PY_mb_juan},
        {"5264", "kang", (uint8_t *)PY_mb_kang},
        {"5364", "keng", (uint8_t *)PY_mb_keng},
        {"5664", "kong", (uint8_t *)PY_mb_kong},
        {"5824", "kuai", (uint8_t *)PY_mb_kuai},
        {"5826", "kuan", (uint8_t *)PY_mb_kuan},
        {"5264", "lang", (uint8_t *)PY_mb_lang},
        {"5366", "leng", (uint8_t *)PY_mb_leng},
        {"5426", "lian", (uint8_t *)PY_mb_lian},
        {"5426", "liao", (uint8_t *)PY_mb_liao},
        {"5464", "ling", (uint8_t *)PY_mb_ling},
        {"5664", "long", (uint8_t *)PY_mb_long},
        {"5826", "luan", (uint8_t *)PY_mb_luan},
        {"6264", "mang", (uint8_t *)PY_mb_mang},
        {"6364", "meng", (uint8_t *)PY_mb_meng},
        {"6426", "mian", (uint8_t *)PY_mb_mian},
        {"6426", "miao", (uint8_t *)PY_mb_miao},
        {"6464", "ming", (uint8_t *)PY_mb_ming},
        {"6264", "nang", (uint8_t *)PY_mb_nang},
        {"6364", "neng", (uint8_t *)PY_mb_neng},
        {"6426", "nian", (uint8_t *)PY_mb_nian},
        {"6426", "niao", (uint8_t *)PY_mb_niao},
        {"6464", "ning", (uint8_t *)PY_mb_ning},
        {"6664", "nong", (uint8_t *)PY_mb_nong},
        {"6826", "nuan", (uint8_t *)PY_mb_nuan},
        {"7264", "pang", (uint8_t *)PY_mb_pang},
        {"7364", "peng", (uint8_t *)PY_mb_peng},
        {"7426", "pian", (uint8_t *)PY_mb_pian},
        {"7426", "piao", (uint8_t *)PY_mb_piao},
        {"7464", "ping", (uint8_t *)PY_mb_ping},
        {"7426", "qian", (uint8_t *)PY_mb_qian},
        {"7426", "qiao", (uint8_t *)PY_mb_qiao},
        {"7464", "qing", (uint8_t *)PY_mb_qing},
        {"7826", "quan", (uint8_t *)PY_mb_quan},
        {"7264", "rang", (uint8_t *)PY_mb_rang},
        {"7364", "reng", (uint8_t *)PY_mb_reng},
        {"7664", "rong", (uint8_t *)PY_mb_rong},
        {"7826", "ruan", (uint8_t *)PY_mb_ruan},
        {"7264", "sang", (uint8_t *)PY_mb_sang},
        {"7364", "seng", (uint8_t *)PY_mb_seng},
        {"7424", "shai", (uint8_t *)PY_mb_shai},
        {"7426", "shan", (uint8_t *)PY_mb_shan},
        {"7426", "shao", (uint8_t *)PY_mb_shao},
        {"7434", "shei", (uint8_t *)PY_mb_shei},
        {"7436", "shen", (uint8_t *)PY_mb_shen},
        {"7468", "shou", (uint8_t *)PY_mb_shou},
        {"7482", "shua", (uint8_t *)PY_mb_shua},
        {"7484", "shui", (uint8_t *)PY_mb_shui},
        {"7486", "shun", (uint8_t *)PY_mb_shun},
        {"7486", "shuo", (uint8_t *)PY_mb_shuo},
        {"7664", "song", (uint8_t *)PY_mb_song},
        {"7826", "suan", (uint8_t *)PY_mb_suan},
        {"8264", "tang", (uint8_t *)PY_mb_tang},
        {"8364", "teng", (uint8_t *)PY_mb_teng},
        {"8426", "tian", (uint8_t *)PY_mb_tian},
        {"8426", "tiao", (uint8_t *)PY_mb_tiao},
        {"8464", "ting", (uint8_t *)PY_mb_ting},
        {"8664", "tong", (uint8_t *)PY_mb_tong},
        {"8826", "tuan", (uint8_t *)PY_mb_tuan},
        {"9264", "wang", (uint8_t *)PY_mb_wang},
        {"9364", "weng", (uint8_t *)PY_mb_weng},
        {"9426", "xian", (uint8_t *)PY_mb_xian},
        {"9426", "xiao", (uint8_t *)PY_mb_xiao},
        {"9464", "xing", (uint8_t *)PY_mb_xing},
        {"9826", "xuan", (uint8_t *)PY_mb_xuan},
        {"9264", "yang", (uint8_t *)PY_mb_yang},
        {"9464", "ying", (uint8_t *)PY_mb_ying},
        {"9664", "yong", (uint8_t *)PY_mb_yong},
        {"9826", "yuan", (uint8_t *)PY_mb_yuan},
        {"9264", "zang", (uint8_t *)PY_mb_zang},
        {"9364", "zeng", (uint8_t *)PY_mb_zeng},
        {"9424", "zhai", (uint8_t *)PY_mb_zhai},
        {"9426", "zhan", (uint8_t *)PY_mb_zhan},
        {"9426", "zhao", (uint8_t *)PY_mb_zhao},
        {"9436", "zhen", (uint8_t *)PY_mb_zhen},
        {"9468", "zhou", (uint8_t *)PY_mb_zhou},
        {"9482", "zhua", (uint8_t *)PY_mb_zhua},
        {"9484", "zhui", (uint8_t *)PY_mb_zhui},
        {"9486", "zhun", (uint8_t *)PY_mb_zhun},
        {"9486", "zhuo", (uint8_t *)PY_mb_zhuo},
        {"9664", "zong", (uint8_t *)PY_mb_zong},
        {"9826", "zuan", (uint8_t *)PY_mb_zuan},
        {"24264", "chang", (uint8_t *)PY_mb_chang},
        {"24364", "cheng", (uint8_t *)PY_mb_cheng},
        {"24664", "chong", (uint8_t *)PY_mb_chong},
        {"24826", "chuan", (uint8_t *)PY_mb_chuan},
        {"48264", "guang", (uint8_t *)PY_mb_guang},
        {"48264", "huang", (uint8_t *)PY_mb_huang},
        {"54264", "jiang", (uint8_t *)PY_mb_jiang},
        {"54664", "jiong", (uint8_t *)PY_mb_jiong},
        {"58264", "kuang", (uint8_t *)PY_mb_kuang},
        {"54264", "liang", (uint8_t *)PY_mb_liang},
        {"64264", "niang", (uint8_t *)PY_mb_niang},
        {"74264", "qiang", (uint8_t *)PY_mb_qiang},
        {"74664", "qiong", (uint8_t *)PY_mb_qiong},
        {"74264", "shang ", (uint8_t *)PY_mb_shang},
        {"74364", "sheng", (uint8_t *)PY_mb_sheng},
        {"74824", "shuai", (uint8_t *)PY_mb_shuai},
        {"74826", "shuan", (uint8_t *)PY_mb_shuan},
        {"94264", "xiang", (uint8_t *)PY_mb_xiang},
        {"94664", "xiong", (uint8_t *)PY_mb_xiong},
        {"94264", "zhang", (uint8_t *)PY_mb_zhang},
        {"94364", "zheng", (uint8_t *)PY_mb_zheng},
        {"94664", "zhong", (uint8_t *)PY_mb_zhong},
        {"94824", "zhuai", (uint8_t *)PY_mb_zhuai},
        {"94826", "zhuan", (uint8_t *)PY_mb_zhuan},
        {"248264", "chuang", (uint8_t *)PY_mb_chuang},
        {"748264", "shuang", (uint8_t *)PY_mb_shuang},
        {"948264", "zhuang", (uint8_t *)PY_mb_zhuang},
};

const uint8_t fontStock[] = {"啊阿埃挨哎唉哀皑癌蔼矮艾碍爱隘鞍氨安俺按暗岸胺案肮昂盎凹敖熬翱袄傲奥懊澳芭捌扒叭吧笆八疤巴拔跋靶把耙坝霸罢爸白柏百摆佰败拜稗斑班搬扳般颁板版扮拌伴瓣半办绊邦帮梆榜膀绑棒磅蚌镑傍谤苞胞包褒剥薄雹保堡饱宝抱报暴豹鲍爆杯碑悲卑北辈背贝钡倍狈备惫焙被奔苯本笨崩绷甭泵蹦迸逼鼻比鄙笔彼碧蓖蔽毕毙毖币庇痹闭敝弊必辟壁臂避陛鞭边编贬扁便变卞辨辩辫遍标彪膘表鳖憋别彬斌濒滨宾摈兵冰柄丙秉饼炳病并玻菠播拨钵波博勃搏铂箔伯帛舶脖膊渤泊驳捕卜哺补埠不布步簿部怖擦猜裁材才财睬踩采彩菜蔡餐参蚕残惭惨灿苍舱仓沧藏操糙槽曹草厕策侧册测层蹭插叉茬茶查碴搽察岔差诧拆柴掺蝉馋谗缠铲产阐颤昌猖场尝常长偿肠厂敞畅唱倡超抄钞朝嘲潮巢吵炒车扯撤掣彻澈郴臣辰尘晨忱沉陈趁衬撑称城橙成呈乘程惩澄诚承逞骋秤吃痴持匙池迟弛驰耻齿侈尺赤翅斥炽充冲虫崇宠抽酬畴踌稠愁筹仇绸瞅丑臭初出橱厨躇锄雏滁除楚储矗搐触处揣川穿椽传船喘串疮窗幢床闯创吹炊捶锤垂春椿醇唇淳纯蠢戳绰疵茨磁雌辞慈瓷词此刺赐次聪葱囱匆从丛凑粗醋簇促蹿篡窜摧崔催脆粹淬翠村存寸磋撮搓措挫错搭达答瘩打大呆歹傣戴带殆代贷袋待逮怠耽担丹单郸掸胆旦氮但惮淡诞弹蛋当挡党荡档刀捣蹈倒岛祷导到稻悼道盗德得的蹬灯登等瞪凳邓堤低滴迪敌笛狄涤翟嫡抵底地蒂第帝弟递缔颠掂滇碘点典靛垫电佃甸店惦奠淀殿碉叼雕凋刁掉吊钓调跌爹碟蝶迭谍叠丁盯叮钉顶鼎锭定订丢东冬董懂动栋侗恫冻洞兜抖斗陡豆逗痘都督毒犊独读堵睹赌杜镀肚度渡妒端短锻段断缎堆兑队对墩吨蹲敦顿囤钝盾遁掇哆多夺垛躲朵跺舵剁惰堕蛾峨鹅俄额讹娥恶厄扼遏鄂饿恩而儿耳尔饵洱二贰发罚筏伐乏阀法珐藩帆番翻樊矾钒繁凡烦反返范贩犯饭泛坊芳方肪房防妨仿访纺放菲非啡飞肥匪诽吠肺废沸费芬酚吩氛分纷坟焚汾粉奋份忿愤粪丰封枫蜂峰锋风疯烽逢冯缝讽奉凤佛否夫敷肤孵扶拂辐幅氟符伏俘服浮涪福袱弗甫抚辅俯釜斧脯腑府腐赴副覆赋复傅付阜父腹负富讣附妇缚咐噶嘎该改概钙盖溉干甘杆柑竿肝赶感秆敢赣冈刚钢缸肛纲岗港杠篙皋高膏羔糕搞镐稿告哥歌搁戈鸽胳疙割革葛格蛤阁隔铬个各给根跟耕更庚羹埂耿梗工攻功恭龚供躬公宫弓巩汞拱贡共钩勾沟苟狗垢构购够辜菇咕箍估沽孤姑鼓古蛊骨谷股故顾固雇刮瓜剐寡挂褂乖拐怪棺关官冠观管馆罐惯灌贯光广逛瑰规圭硅归龟闺轨鬼诡癸桂柜跪贵刽辊滚棍锅郭国果裹过哈骸孩海氦亥害骇憨邯韩含涵寒函喊罕翰撼捍旱憾悍焊汗汉夯杭航壕嚎豪毫郝好耗号浩呵喝荷菏核禾和何合盒貉阂河涸赫褐鹤贺嘿黑痕很狠恨哼亨横衡恒轰哄烘虹鸿洪宏弘红喉侯猴吼厚候后呼乎忽瑚壶葫胡蝴狐糊湖弧虎唬护互沪户花哗华猾滑画划化话槐徊怀淮坏欢环桓还缓换患唤焕涣宦幻荒慌黄磺蝗簧皇凰惶煌晃幌恍谎灰挥辉徽恢蛔回毁悔慧卉惠晦贿秽会烩汇讳诲绘荤昏婚魂浑混豁活伙火获或惑霍货祸击圾基机畸稽积箕肌饥迹激讥鸡姬绩缉吉极棘辑籍集及急疾汲即嫉级挤几脊己蓟技冀季伎祭剂悸济寄寂计记既忌际妓继纪嘉枷夹佳家加荚颊贾甲钾假稼价架驾嫁歼监坚尖笺间煎兼肩艰奸缄茧检柬碱硷拣捡简俭剪减荐槛鉴践贱见键箭件健舰剑饯渐溅涧建僵姜将浆江疆蒋桨奖讲匠酱降蕉椒礁焦胶交郊浇骄娇嚼搅铰矫侥脚狡角饺缴绞剿教酵轿较叫窖揭接皆秸街阶截劫节桔杰捷睫竭洁结解姐戒藉芥界借介疥诫届巾筋斤金今津襟紧锦仅谨进靳晋禁近烬浸尽劲荆兢茎睛晶鲸京惊精粳经井警景颈静境敬镜径痉靖竟竞净炯窘揪究纠玖韭久灸九酒厩救旧臼舅咎就疚鞠拘狙疽居驹菊局咀矩举沮聚拒据巨具距踞锯俱句惧炬剧捐鹃娟倦眷卷绢撅抉掘倔爵觉决诀绝均菌钧军君峻俊竣浚郡骏喀咖卡咯开揩楷凯慨刊堪勘坎砍看康慷糠扛抗亢炕考拷烤靠坷苛柯棵磕颗科壳咳可渴克刻客课肯啃垦恳坑吭空恐孔控抠口扣寇枯哭窟苦酷库裤夸垮挎跨胯块筷侩快宽款匡筐狂框矿眶旷况亏盔岿窥葵奎魁傀馈愧溃坤昆捆困括扩廓阔垃拉喇蜡腊辣啦莱来赖蓝婪栏拦篮阑兰澜谰揽览懒缆烂滥琅榔狼廊郎朗浪捞劳牢老佬姥酪烙涝勒乐雷镭蕾磊累垒擂肋类泪棱楞冷厘梨犁黎篱狸离漓理李里鲤礼莉荔吏栗丽厉励砾历利傈例俐痢立粒沥隶力璃哩俩联莲连镰廉怜涟帘敛脸链恋炼练粮凉梁粱良两辆量晾亮谅撩聊僚疗燎寥辽潦了撂镣廖料列裂烈劣猎琳林磷霖临邻鳞淋凛赁吝拎玲菱零龄铃伶羚凌灵陵岭领另令溜琉榴硫馏留刘瘤流柳六龙聋咙笼窿隆垄拢陇楼娄搂篓漏陋芦卢颅庐炉掳卤虏鲁麓碌露路赂鹿潞禄录陆戮驴吕铝侣旅履屡缕虑氯律率滤绿峦挛孪滦卵乱掠略抡轮伦仑沦纶论萝螺罗逻锣箩骡裸落洛骆络妈麻玛码蚂马骂嘛吗埋买麦卖迈脉瞒馒蛮满蔓曼慢漫谩芒茫盲氓忙莽猫茅锚毛矛铆卯茂冒帽貌贸么玫枚梅酶霉煤没眉媒镁每美昧寐妹媚门闷们萌蒙檬盟锰猛梦孟眯醚靡糜迷谜弥米秘觅泌蜜密幂棉眠绵冕免勉娩缅面苗描瞄藐秒渺庙妙蔑灭民抿皿敏悯闽明螟鸣铭名命谬摸摹蘑模膜磨摩魔抹末莫墨默沫漠寞陌谋牟某拇牡亩姆母墓暮幕募慕木目睦牧穆拿哪呐钠那娜纳氖乃奶耐奈南男难囊挠脑恼闹淖呢馁内嫩能妮霓倪泥尼拟你匿腻逆溺蔫拈年碾撵捻念娘酿鸟尿捏聂孽啮镊涅您柠狞凝宁拧泞牛扭钮纽脓浓农弄奴努怒女暖虐挪懦糯诺哦欧鸥殴藕呕偶沤啪趴爬帕怕琶拍排牌徘湃派攀潘盘磐盼畔判叛乓庞旁耪胖抛咆刨炮袍跑泡呸胚培裴赔陪配佩沛喷盆砰抨烹澎彭蓬棚硼篷膨朋鹏捧碰坯砒霹批披劈琵毗啤脾疲皮匹痞僻屁譬篇偏片骗飘漂瓢票撇瞥拼频贫品聘乒坪苹萍平凭瓶评屏坡泼颇婆破魄迫粕剖扑铺仆莆葡菩蒲埔朴圃普浦谱曝瀑期欺栖戚妻七凄漆柒沏其棋奇歧畦崎脐齐旗祈祁骑起岂乞企启契砌器气迄弃汽泣讫掐恰洽牵扦钎铅千迁签仟谦乾黔钱钳前潜遣浅谴堑嵌欠歉枪呛腔羌墙蔷强抢橇锹敲悄桥瞧乔侨巧鞘撬翘峭俏窍切茄且怯窃钦侵亲秦琴勤芹擒禽寝沁青轻氢倾卿清擎晴氰情顷请庆琼穷秋丘邱球求囚酋泅趋区蛆曲躯屈驱渠取娶龋趣去圈颧权醛泉全痊拳犬券劝缺炔瘸却鹊榷确雀裙群然燃冉染瓤壤攘嚷让饶扰绕惹热壬仁人忍韧任认刃妊纫扔仍日戎茸蓉荣融熔溶容绒冗揉柔肉茹蠕儒孺如辱乳汝入褥软阮蕊瑞锐闰润若弱撒洒萨腮鳃塞赛三叁伞散桑嗓丧搔骚扫嫂瑟色涩森僧莎砂杀刹沙纱傻啥煞筛晒珊苫杉山删煽衫闪陕擅赡膳善汕扇缮墒伤商赏晌上尚裳梢捎稍烧芍勺韶少哨邵绍奢赊蛇舌舍赦摄射慑涉社设砷申呻伸身深娠绅神沈审婶甚肾慎渗声生甥牲升绳省盛剩胜圣师失狮施湿诗尸虱十石拾时什食蚀实识史矢使屎驶始式示士世柿事拭誓逝势是嗜噬适仕侍释饰氏市恃室视试收手首守寿授售受瘦兽蔬枢梳殊抒输叔舒淑疏书赎孰熟薯暑曙署蜀黍鼠属术述树束戍竖墅庶数漱恕刷耍摔衰甩帅栓拴霜双爽谁水睡税吮瞬顺舜说硕朔烁斯撕嘶思私司丝死肆寺嗣四伺似饲巳松耸怂颂送宋讼诵搜艘擞嗽苏酥俗素速粟僳塑溯宿诉肃酸蒜算虽隋随绥髓碎岁穗遂隧祟孙损笋蓑梭唆缩琐索锁所塌他它她塔挞蹋踏胎苔抬台泰酞太态汰坍摊贪瘫滩坛檀痰潭谭谈坦毯袒碳探叹炭汤塘搪堂棠膛唐糖倘躺淌趟烫掏涛滔绦萄桃逃淘陶讨套特藤腾疼誊梯剔踢锑提题蹄啼体替惕涕剃屉天添填田甜恬舔腆挑条迢眺跳贴铁帖厅听烃汀廷停亭庭挺艇通桐酮瞳同铜彤童桶捅筒统痛偷投头透凸秃突图徒途涂屠土吐兔湍团推颓腿蜕褪退吞屯臀拖托脱鸵陀驮驼椭妥拓唾挖哇蛙洼娃瓦袜歪外豌弯湾玩顽丸烷完碗挽晚皖惋宛婉万腕汪王亡枉网往旺望忘妄威巍微危韦违桅围唯惟为潍维苇萎委伟伪尾纬未蔚味畏胃喂魏位渭谓尉慰卫瘟温蚊文闻纹吻稳紊问嗡翁瓮挝蜗涡窝我卧握沃巫呜钨乌污诬屋无芜梧吾吴毋武五捂午舞伍侮坞戊雾晤物勿务悟误昔熙析西硒矽晰嘻吸锡牺稀息希悉膝夕惜熄烯溪汐犀檄袭席习媳喜铣洗系隙戏细瞎虾匣霞辖暇峡侠狭下厦夏吓掀锨先仙鲜纤咸贤衔舷闲涎弦嫌显险现献县腺馅羡宪陷限线相厢镶香箱襄湘乡翔祥详想响享项巷橡像向象萧硝霄削哮嚣销消宵淆晓小孝校肖啸笑效楔些歇蝎鞋协挟携邪斜胁谐写械卸蟹懈泄泻谢屑薪芯锌欣辛新忻心信衅星腥猩惺兴刑型形邢行醒幸杏性姓兄凶胸匈汹雄熊休修羞朽嗅锈秀袖绣墟戌需虚嘘须徐许蓄酗叙旭序畜恤絮婿绪续轩喧宣悬旋玄选癣眩绚靴薛学穴雪血勋熏循旬询寻驯巡殉汛训讯逊迅压押鸦鸭呀丫芽牙蚜崖衙涯雅哑亚讶焉咽阉烟淹盐严研蜒岩延言颜阎炎沿奄掩眼衍演艳堰燕厌砚雁唁彦焰宴谚验殃央鸯秧杨扬佯疡羊洋阳氧仰痒养样漾邀腰妖瑶摇尧遥窑谣姚咬舀药要耀椰噎耶爷野冶也页掖业叶曳腋夜液一壹医揖铱依伊衣颐夷遗移仪胰疑沂宜姨彝椅蚁倚已乙矣以艺抑易邑屹亿役臆逸肄疫亦裔意毅忆义益溢诣议谊译异翼翌绎茵荫因殷音阴姻吟银淫寅饮尹引隐印英樱婴鹰应缨莹萤营荧蝇迎赢盈影颖硬映哟拥佣臃庸雍踊蛹咏泳涌永恿勇用幽优悠忧尤由邮铀犹油游酉有友右佑釉诱又幼迂淤于盂榆虞愚舆余俞逾鱼愉渝渔隅予娱雨与屿禹宇语羽玉域芋郁吁遇喻峪御愈欲狱育誉浴寓裕预豫驭鸳渊冤元垣袁原援辕园员圆猿源缘远苑愿怨院曰约越跃钥岳粤月悦阅耘云郧匀陨允运蕴酝晕韵孕匝砸杂栽哉灾宰载再在咱攒暂赞赃脏葬遭糟凿藻枣早澡蚤躁噪造皂灶燥责择则泽贼怎增憎曾赠扎喳渣札轧铡闸眨栅榨咋乍炸诈摘斋宅窄债寨瞻毡詹粘沾盏斩辗崭展蘸栈占战站湛绽樟章彰漳张掌涨杖丈帐账仗胀瘴障招昭找沼赵照罩兆肇召遮折哲蛰辙者锗蔗这浙珍斟真甄砧臻贞针侦枕疹诊震振镇阵蒸挣睁征狰争怔整拯正政帧症郑证芝枝支吱蜘知肢脂汁之织职直植殖执值侄址指止趾只旨纸志挚掷至致置帜峙制智秩稚质炙痔滞治窒中盅忠钟衷终种肿重仲众舟周州洲诌粥轴肘帚咒皱宙昼骤珠株蛛朱猪诸诛逐竹烛煮拄瞩嘱主著柱助蛀贮铸筑住注祝驻抓爪拽专砖转撰赚篆桩庄装妆撞壮状椎锥追赘坠缀谆准捉拙卓桌琢茁酌啄着灼浊兹咨资姿滋淄孜紫仔籽滓子自渍字鬃棕踪宗综总纵邹走奏揍租足卒族祖诅阻组钻纂嘴醉最罪尊遵昨左佐柞做作坐座丌兀丐廿丕亘丞孬噩禺匕夭胤毓亟芈孛厥赝叵匮匾卦剌剜剽仨攸佚佝佟佗伲伽佴侃侏佻侪佼侬俨俪俅俚俣俜俑俟俸倩偌俳倏倭偾偃偕偎偬偻傥僖儆僭僬僮儋佘俎兮巽匍訇匐夙亵禀嬴蠃羸冱冽冼凇冥讦讪讷诃诏诓诘诜诟诤诨诩诮诳诶谄谌谏谑谒谡谥谧谪谮谲谵阡阱阪陂陟陧陲隍隗邬邸邰郢郜郛郫郯郾鄄鄢鄞鄣鄱鄯刍奂劭叟塾圩圬圪圳圹坜坂坩垅坫坼坻坨坭坶坳垭垤垌垲垴垠埙埴埯埸堋堀塥馨懿芊芙芫芸芘芷芮苋茉苷苒苘苻苓茑茆茔茕苕茜荑荛荜莒茼茴茱莛荞茯荀茗茭荦荨茛荸莴莓莜莅荼莘莞莺菁堇萘菖萑萃菅菀萦菡葙葺蒉葸葶萱葭蓐蓦蒽蓓蓊蒿蓠蒡蒹蔺蔻蓿蓼蕙蕨瞢蕃薇薏薰藿弈奕奚尬尴抻拊拮捋揶捱捺掊掮掼摅摁摞摺撸撙撺擀擤弋叩叨吒吖吆呓呔呖呃吡呗吣吲咂咔呷呱呤咚咛呦咝哒咧咦哔呲咣咻咿哚咩咪哧唠哽唔唢唣唏唑唧唪啧喏喵唷啖啵啶啷唳唰喋嗒喃喱喟啾嗖喑嗟喽喔喙嗪嗷嗉嘟嗑嗫嗬嗔嗦嗝嗄嗯嘞嘈嘁嘤嘣嘀嘧嘭噘嘹噗噢噜噤囔囡帼帷幄幔幛幡岌岐岖岘岑岚岜岬岱岣岷峄峒峋峥崂崴崽嵋嵊嵩嶂嶙巅彷徂徇徉後徕徙徜徨徭徵徼狎狍狒狯狩狲猗猡猊猝猕猥猬獗獠饨饴饷饽馀馄馍馑馓馕庵庾忖忏怃忮忤忾怅怙怛怏怍怊怿怡恸恹恻恺恂恪悖悚悭悝悃悒悌悛惬悻悱惝惘惆惚悴愠愦愕愣惴愀愎愫慊慵憬憔憧憷懔懵闫闱闵闶闾阈阏阕阖阙阚沣沅沐沌汨汩汴汶沆泔沭泷泸泱泠泫泮沱泓泯泾洌浃浈洇洄浍洵浏浒浔涓涔浠浣渚淇淅淞渎淦淙渖渌涮渫湮溲湟溆渲渥湄滟溘溻滏滂溟潢潇漕漪漩澉澌潸潲潼潺濑濉澹澶濡濞濠濯瀚宕宥宸骞寮寰迤迩迦逅逦逑逍逡逵遒遐遨遢遛彗弩弭妃妣姊妞妤妲妯姗妾娅娆姝娈姣姘姹娉娲娴娑娣娓婀婧婊婕婢婵媪媛婷媾嫒嫔嫣嫱嫦嬉嬗嬷孀孚孢驵驷驸驿驽骁骅骈骊骐骠纡纣绛绠绡绫绮绯缍绻绾缁缇缈缟缢缤幺玎玑玢玟珏珂珑玷玳珀珉珈珥珙顼琊珩珞玺琏琪瑛琦琥琨琰琮琬琛琚瑁瑜瑕瑙瑾璜璎璀璇璋璞璨璐璧韬杓杞杈枇杳杵枨枰柚栀枸柢栎桎桢桦桧桀栾栩梵梓棰椁棣椹楠榄楫槌榈榉楦楣榛榻榫榭槁槟榕槿樘橄樵檎樽樨檐殂殇殒殓殍殚殡轱轶轺轼轾辂辄辇戟旮昊昙昕昀炅昱昵晟晔晁晏晖曜曦贻赅赈觊觎觐觑牦牯犄犒挲掰毽氅敕肽肫肴胧胄胴胭脍胼朕豚腌腚腱腠腩膈朦膻欷歃歆飒飕飙斐斓旌旎旖炀炜炖炝烀炷炫烨焐焖焯焱煜煨煅煲煸熘熳熵熨熠焘煦熹戾扈扉祉祛祢祗祠祯祧祺禅禚禧忑忐怼恁恙沓淼矶砀砘砺砥砬砣硌碣磬盱盹眇眈眵眸睑睿瞌瞑瞟瞠瞰町畈钊钗钿铛铤铮铿锃锒锴锵镯矬雉秣稆嵇稔稷黏馥皈皎皓皙甬鸠鸢鸨鸩鸪鸫鸬鸷鸾鹂鹄鹉鹌鹑鹜鹞鹦鹧鹬鹭疸瘙瘠癖癫翊穹窈窕窦衩衲袂裆裢裱褚裨褓褛褊褴褶襁胥矜耔耦聆聍聒覃颔颛颢虔虬蚪蚓蚩蚯蛐蜓蛟蜃蜇蜈蜊蜉蝠蝌蝣蝥螨螵螳罄舐竽笈笃笙笠笤筱箐箸箢箫舫舸衾袅袈裘裟羯粼粽糍糗艮暨羿翎翡翩赳趄趔豇豉酰醪跆跷踹蹉蹂貂觞靓雳雯霆霏霭霾龈隼隽雎瞿銮鑫鱿鲅鲇鲟鲢鲨鲩鲫鲶鳄鳅鳌靼鞑骰骷骼髅鬓麾麒鏖麝麟黛鼾魅\0"};
typedef uint8_t cChar[5];
uint32_t getSentenceWCharCnt(uint8_t *sentence);
uint32_t getW_charFromSentence(uint8_t *sentence, cChar *chineseLetter);
int main(void)
{

    int compareSucCnt = 0;
    uint8_t listStr[512];
    uint8_t codeLineStr[1024];
    uint8_t codeStr[1024 * 1024];
    int i, j, k, f, cnt = 0;
    uint8_t flag = 0;
    int fontStockCnt = 0;
    cChar *temp;
    cChar *compare;

    cChar nihao = {"啊\0"};
    printf("啊编码 : ");
    for(i = 0 ; i < strlen(nihao);i++)
    {
        printf("%02x",nihao[i]);
    }
    printf("\r\n");


    printf("cchar compare start\r\n");
    temp = malloc(256 * sizeof(cChar));
    compare = malloc(5000 * sizeof(cChar));
    memset(temp, 0, 256 * sizeof(cChar));
    memset(compare, 0, 5000 * sizeof(cChar));
    memset(listStr, 0, 512);
    memset(codeLineStr, 0, 1024);
    memset(codeStr, 0, 1024 * 1024);
    if (temp == NULL)
    {
        printf("temp malloc failed\r\n");
        return 0;
    }

    if (compare == NULL)
    {
        printf("compare malloc failed\r\n");
        return 0;
    }
    printf("prepare for the compare list\r\n");
    printf("py cate : %d\r\n", sizeof(py_index3) / sizeof(py_index));
    fontStockCnt = getW_charFromSentence(fontStock, compare);
    printf("fontStockCnt : %d\r\n", fontStockCnt);

    py_index *list = &py_index3;
    int fd = fopen("list.txt", "w+");
    if (fd <= 0)
    {
        printf("file open failed\r\n");
        return 0;
    }
    for (i = 0;i < sizeof(py_index3)/sizeof(py_index); i++)
    {
        cnt = 0;
        memset(temp, 0, 256 * sizeof(cChar));
        memset(codeLineStr, 0, sizeof(codeLineStr));
        memset(listStr, 0, sizeof(listStr));
        cnt = getW_charFromSentence(list->pymb, temp);
        printf("py - %s charscnt - %d\r\n", list->py, cnt);
        compareSucCnt = 0;
        for (k = 0; k < cnt; k++)
        {
        
            if (strstr(fontStock, temp[k]) != NULL)
            {
                compareSucCnt++;
                strcat(listStr, temp[k]);
            }
        }

        sprintf(codeLineStr, "const uint8_t PY_mb_%s[] = {\"%s\\0\"};\/\/匹配字数 : %d  检查出的字数 :%d 源列表字数 : %d \r", list->py, listStr, compareSucCnt, getSentenceWCharCnt(listStr),cnt);
        strcat(codeStr, codeLineStr);

        list++;
        if (list == NULL)
        {
            printf("break \r\n");
            break;
        }
    }
    printf("cchar compare finish\r\n");

    int wrLen = fwrite(codeStr, 1, strlen(codeStr), fd);
    printf("write file len : %d\r\n", wrLen);
    if (fd > 0)
    {
        fclose(fd);
    }
    free(temp);
    free(compare);
    return 0;
}

uint32_t getSentenceWCharCnt(uint8_t *sentence)
{
    uint32_t chineseCount = 0;
    for (int i = 0; i < strlen((char *)sentence);)
    {
        if ((sentence[i] & 0x80) == 0x00)
        {
            i++; // ASCII字符，占用一个字节，不计数
        }
        else if ((sentence[i] & 0xE0) == 0xC0)
        {
            i += 2; // UTF-8编码的中文字符，占用3个字节
            chineseCount++;
        }
        else if ((sentence[i] & 0xF0) == 0xE0)
        {
            i += 3; // UTF-8编码的中文字符，占用4个字节
            chineseCount++;
        }
        else
        {
            i++; // 其他情况（可能是错误编码），继续检查下一个字节
        }
    }

    return chineseCount;
}

uint32_t getW_charFromSentence(uint8_t *sentence, cChar *chineseLetter)
{
    uint32_t chineseCount = 0;
    char *sLetter;
    cChar *le = chineseLetter;
    for (int i = 0; i < strlen((char *)sentence);)
    {
        if ((sentence[i] & 0x80) == 0x00)
        {
            i++; // ASCII字符，占用一个字节，不计数
        }
        else if ((sentence[i] & 0xE0) == 0xC0)
        {
            sLetter = &(sentence[i]);
            memcpy(*le, sLetter, 2);
            le++;
            i += 2; // UTF-8编码的中文字符，占用3个字节
            chineseCount++;
        }
        else if ((sentence[i] & 0xF0) == 0xE0)
        {
            sLetter = &(sentence[i]);
            memcpy(*le, sLetter, 3);
            le++;
            i += 3; // UTF-8编码的中文字符，占用4个字节
            chineseCount++;
        }
        else
        {
            i++; // 其他情况（可能是错误编码），继续检查下一个字节
        }
    }
    return chineseCount;
}