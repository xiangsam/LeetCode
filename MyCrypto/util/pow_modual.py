# -*- coding: utf-8 -*-
def quickPow(x,n,m):
    """caculate x^n %m"""
    d = 1
    while n > 0:
        if n % 2 == 1:
            d = (d * x) % m
            n = (n-1)//2
        else:
            n = n // 2
        x = x  * x % m
    return d
def Pow(x,n,m):
    d = 1
    for i in range(n):
        d = (d % m) * (x%m) % m
    return d
if __name__ == '__main__':
    x = [7, 5, 1494462659429290047815067355171411187560751791530, 
         22490812876539885046336053040043361022772062226905764414319531416752624982967181455912526153033030222985778230314070837549143068021815197910334221004333099,
         237218075278892229535140238768762235405145645557640724744207466370544846457682663369976322798944392433104280595584635896821245048737637289361896703300454795175488861724813324867455119120284612785871304351940501930714775024417724051440337510897547661217466354700893011496892348407228806138461120064957907686566,
         448491664748214835887077572737743989471818983924746533195711112723370968680112145505675868905886297697651811535959153343019297445815718781370807622258565317729681110144781420923700723193680834808549790079348059612669341617763791748262779560287414722951999863579554855226385841903174595011558143906566236113746355880815410935162653615576832860612181499713446185302492149321184607038850277,
        ]
    n = [16, 1003, 65537, 65537, 65537,
         266848195381815818463717950266554236453862598799637312683425703733349860929573593996414020829279843574050749733141808826377733991992433000295290381444934817157435190251178268111713086611665708753888640498769964215272509919856595016440707694201919276657450513307401642404169770745634306482286288562684063317756864776774548994812022552274677735053131675109617882635817658233698378909301711242970820585209428037532351125028227556492657705501994644156977193457255573644987541990311834672767028439520378145222935082885623390192713665176848108677291865357438200
        ]
    m = [3, 31, 2268838711304724304304396119509416774597723292474, 
         26381036806254391211255825330031625908895486635496820170811397576118892705526151526139312916798859030242219181178517837920904022720459931859633170905729517,
         349972806688784936669965759420500287481274799328355633592840001661382340587247200055746522814275902430370330954725697648747610084477917676220179203273361291098368287612837135979510900982047154261023406927515096043384562410643544643505195484211397819374480917731785250826080723518532061522456937734714740424476,
         26449610480694582663087914798262349275307583705769208320615999887968533547578043032399193471649467130397212338172281740898344480836053483980415141663259446884375373371451231004101622624801199838411707260636384692208754088842619258012627585405663559933995516981379631336446313020148817646717985549051301115238527677472914852742788256890259402224899453419484216558327523122341749054612967901747155276100157913910547784136439888489952724508554613632641420487039242881743232756168292709989984925436911267322885917953348064673021283822937158706678666372103627074163021260578078017304088904154859161289037070912220207946945
        ]
    for i in range(len(x)):
        print('{}^{} % {} = '.format(x[i], n[i], m[i]))
        print(quickPow(x[i],n[i],m[i]))
        print('\n')
        #print(Pow(x,n,m))

