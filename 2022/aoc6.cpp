#include <array>
#include <iostream>
#include <string>

using namespace std;

const int LEADER = 14;

bool notunique(string::iterator its[]) {
  for (int i = 0; i < LEADER; i++) {
    for (int j = i + 1; j < LEADER; j++) {
      //      cout << i << " " << j << "\n";
      if (*(its[i]) == *(its[j]))
        return true;
    }
  }
  return false;
}

int main() {

  string input =
      "cvtvbvfbvfbfqfrrtnnmqqmcqqpfplfpphchpcpcfppmwwhhscccjwjnnctcjtjgjbgjjdzj"
      "jwzwfffnhhgppjmpmgppppzbzbrzznttfqqhtqqbssrjjffgssnqnsqnsqnnmlmmztmtqmqc"
      "cqscsshrsrtstrrjwrrswwpnnftfwwwzznsstbbbtzzncnbcnbccwtwctwwjgjcjtccblclg"
      "cgjgngwgbggpbbbbbgcczzfsfbbwlwwnqwnwbnwnmmbjjnfnqfqfvvgvqqvcvggpnpssptpn"
      "pjjvvpdpqpcqpcqqnhhnqncqclcfcfjcjhjdjqddhndnmmvmfmsmdsdwsdswsnsgsmsrmrjj"
      "pzzzzcppczcscsgcczqcqnnpzpbbdqqqqsqlslzljzjdjbjdjvvlhvvnbbjtbbqbdqdggzwg"
      "ghhdssmttjtttmwtmtjjcpjpjptjpjmpptnntgttjpttljjwtjwwrgrvgrvrmvvrvdrdcdmm"
      "vvbpbddfbdbppdccjdjvjpjjgzjzdzfddqcqlccbvbqvqvjqjggqrqdrqrhhwggmvgmgvgrv"
      "vzwzddlzlbbdpbdbtbhthnthttjwtwffwvvrccnpcnclcgcrrgdrrgzgmzggzhhftfppnwpp"
      "qhhmddzhdzzzjqjhqqcgqqmjjwppfrprlrjlrjjlhjlhjjnbnlblbzlbbfjjwfjjdcdndvvb"
      "llfmlmfmvmnnlcnncsnslsvlsvlsltslslqsqzssslqlssqrrpdpwdppsfpsprpffchhcvcp"
      "vvjpjvjmvvrjrqrzqqqlvvzzggcgrcgcmmvnmmchmmswsvwsvwswnwswdwmwzmmqfqrqtrqq"
      "wqlqlmqmsmggpzpjjlvllzplzlbzzbhhglhhwwhfwwpwgwrwlwplppfvflftltffccmcrcgr"
      "cgghgmmbrbppwvvghvhphhztzpzzwbbtpppcnpccnvcvbccvfvmffmtmbttdqdrrfnrnffsg"
      "stttbhhgmmtffhthllsbllsqsllptpwpvpdpsddsgsrrngnpggwbwwppfqfmqfmfvfzzzldl"
      "tdtvdvtvtbvtgpvtnvcsdbwjrqwrfzdhwfwnmtrltdhsfzwwfpscrlsffchnfszqdddsztwz"
      "cbwdwfnljpfdsqgpnjffqfgsprggfwgvfldvzmnrpnzvfscswnzbljtvshzmcztqqwtzdsts"
      "qggqqvvlmspjjcmllcmsndwpllrvlrglphcqjgwzntwqffthrfmfgpcvjvclvdrjrpnwtrls"
      "hlnwgbbznpflsfmgvbwmnwjpnqhmdnsmwnmblqzjfzfcslhntnjhbrvvlfbffsbhrtvjltqr"
      "qszsrpmdghmhsrqlmrjdsgtsgwggdlqptqrvgmwrpcjrnmmmcdpgjzgghqmshhmddfvfrqwn"
      "wvwbvzzpmwzmvvgsqlsgvmtczwnbzrtnzjnpjjghdzsmcgvqpdhltvltbfvgsgzhvqjjnpsp"
      "ngqpvqwvtqrczqzwrclqbnplmvlnvcwdbzlrnwbppvdfzmblnqfpfqlngttrrcjzfjnrnmss"
      "drrvbvhtrfzblzsjbqwbttsshmcmfhrfbfqspvcfmqbwjszmvwqnpszcfhtnqtftvtpvcjrc"
      "nlmfnvlpjzspcnmvvshpsdfhtbhgjcmjmtpmtcbwnlgtnvlwlggbnzfrrqljmjrwjtzfmgbl"
      "lmmjtfhrszfrfpftmpzhzdhfwdbdnwqspjbrlglgdwtfzcrdhwgqltvthbnrqfngjgnddqlc"
      "pjflqzvbhmlzsvpvlzdvhspmchrjlzfgnlpwdnszqdqpnrchdrswfwnflslcpfmbfrplsmch"
      "bgjhhhlzjlvztpdhslrpmmcthhjwfczjtmbmsvzvsqrvzrcnflqldfnhjzlcsfhgrtqtscnb"
      "zqjglgjnqbtprrprrdtqqtlqwdqnmgbglvwtrpnpjqdsmvczbnldvmgmtpmmqbwgjbfsqbjv"
      "njhhlrppptlrjsptpvghbgtvwvsrnggznjsbjpnwpdsqmmjjqjdwshqwzvqgpnlhdldwzmvm"
      "dnhrnhpscrbnbdtmfqwlmrlszljpjdqgjpgcdwtqzsbqsndjdslrstjwbbfnjvrjlbrphqsp"
      "ltjzpvsgccfrmqhfhjmlslncpgpflhjlrzqsffrtcgsvzpjmlqjznscgjrjhzfjbbchvgjgv"
      "fsrpnzdrstdtsltqldfldvfdjqdwsltcbnnvcgvnjpgdjzsbzgfvgvtmghwfmrmblscfdqls"
      "dgcdbgsphfvvvnffcqwlrvnsrjmvvdrjdljlppsfsrmwwvmsqcgtgtfjhqbqvlsnwdwzhncg"
      "prbspjzqnbllwcjnqpfzlhscdtvlldffngwttntsbtlctdfbzjgclgbhhjtlffvtgbdsswcz"
      "lgmwntrrnnbdtflplfbtqcfrhtgjnrltvzqlcvtdthldqrvjdmlntdjzcncrplgmdbqhlrrf"
      "dszrnbrllhgpzzgjnqzrjrtjjntqvdphgvjtbtqfjwvlpprrcvmpjcdmntvtqjvjrhngbtmd"
      "tflpqmlmmvjjjpdlcvntlvlgstbblwfwjrbcqjgzvjjzflfhdvgnhpnqprcvmhsrpmgfcgjp"
      "dbqpmpvlnmzdngzqcqtdsbbqbdhtgpqmqwtcctsvhwmlhpgzgpwwsqngsrwzghfhzbqcpspf"
      "hqbllbvpwgwdnghqnvjtfqtwgvnbfbpcffbwwbfqgqnftpqdtwhmrprpgdlnwrcmdndllwbv"
      "lrrjvmwlbgfwgbhtmbqhfvhlhlthbrljwnwcgsdgsbbzgnwzmjfgnfjcqhspjwctntznjpts"
      "nbpwtfzmrqwjzrmdthfwdvttrcghbjndfmtswhsmdwwwffmgsvshmlhdbwdscjnvrvqnwttl"
      "smfbssnsscftcrpwfbbplbpmvzmttvbgpnjtqqzcfdfwqdphggwbnhfvssmdjvbvtlrcghlt"
      "thqrqdbvjnbqpzjcggrbnrswhvdcrmgncsmhsmstmcbwgbfwvzqtdrpjbgljdgcncgcdslhf"
      "tptnvfhgpsjqqmnsjmqhztnfzqqqhccbnqjlhqcwwbfzgpmbvjszswjlhcqshtqdmwmhpgqg"
      "zbwbtchrdwgnvfqcgcmngtddpzfgjrrssdmcnbtpbhfvfbdgzmcbjqtdqrnrdchtrcfpmtnv"
      "fczdlnjplwccfmzjwwvdsrcjznrcbczdqwshjgvhjpgdgjvtvmdzncrqgffzhcbwstvltqbr"
      "zfbnrrvlntjmzctvnqhdcgvvmmbfplzpwgsdzdtvnwnshnwbwqplbctntslczwhblsnzdcsg"
      "ltvlfvbtvthvlsmzmfgzhpvrvczdhmcpmgqzbdhbcdbstrrtzgrbhhwwghzlgcdtlcjtjdcw"
      "dtqpvpwzrwmhczfsdmwjlgtmzvdbwzdnsztvqzhjpfrqzllgvrsbmhvrlzwtfmpzchftrzlm"
      "ndpwqgcmhdzmjrjvpbnrcmjvzbzlqngmrzcbdwfcwmlnlqsdgbvmvqcsjtwgvtpmqdtdqfrs"
      "hmlgnjqdwsrpjcfnfpjzlhslsvppmgprqlpcfztcngmqgrvqvpcszzgtbpcrghmgnvgplctg"
      "dljhwjgbzmjrdsccdtrwjrrbttzmpvmzlmqdfwdccfzqztdjmcgrcdwghgmmntdwrclshlgn"
      "smhmltwcczncndtglnqvcvbwlvcgqtzpnqnlllchwjwrlhcdlbjlzvhvtjsttqhvhfqbsqjp"
      "fcmpsfshgrrwgprjtfnhsjqqntrjfgjjmjbqwdjlcjjdljpppgvqvgrrwvclbmncmqglhbtj"
      "cfrbjmhqgmlpzgljntqvrcggmrgtbrftvhrnjbvzstlnzrqcgncnjhdrnqcnwcrstvdsgnwz"
      "jzmqsdtwzzjmfgzpslhqclhtjnrlwwfrqgmhsttfdprhgmphzfdfqntwztltnnfqwgdnnbrl"
      "gzmtwqsvhbjjqtcgmghnbchdfgfrdtjnvlgtqdgrfwmgnmpslqmqzdgqztnppbc";

  int c = LEADER;
  string::iterator its[LEADER];

  for (int i = 0; i < LEADER; i++) {
    its[i] = input.begin();
    advance(its[i], i);
  }

  while (notunique(its)) {
    c++;
    for (int i = 0; i < LEADER; i++) {
      its[i]++;
    }
  }

  cout << c << ":" << input.at(c);
}
