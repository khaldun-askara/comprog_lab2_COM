using SweetsMachineCSharpClient.Properties;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SweetsMachineCSharpClient
{
    public partial class Form1 : Form
    {
        SweetsMachine mySM;
        ICreateMachine iCrSM;
        ICoinAcceptor iCoinAcc;
        IStats iStats;
        public Form1()
        {
            InitializeComponent();
            mySM = new SweetsMachine();
            iCrSM = (ICreateMachine)mySM;
            iCoinAcc = (ICoinAcceptor)mySM;
            iStats = (IStats)mySM;


            iCrSM.SetSerialNumber("SM000");
            iCrSM.SetMaxValue(100);

            string tempS = "";
            iStats.GetSerialNumber(ref tempS);
            label_sernum.Text = "Serial Number: " + tempS;
            int temp = 0;
            iCoinAcc.GetMaxValue(ref temp);
            label_maxval.Text = "Max number of coins: " + temp;
            iCoinAcc.GetCurValue(ref temp);
            label_curval.Text = "Cur number of coins: " + temp;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            iCoinAcc.BuyCandy();
            int max = 0, cur = 0;
            iCoinAcc.GetMaxValue(ref max);
            label_maxval.Text = "Max number of coins: " + max;
            iCoinAcc.GetCurValue(ref cur);
            label_curval.Text = "Cur number of coins: " + cur;

            if (max == cur)
            {
                button1.Enabled = false;
                button1.Text = "Конфеты кончились ´• c •`";
                pictureBox1.Image = Resources.SMwithoutsweets;
            }

        }
    }
}
