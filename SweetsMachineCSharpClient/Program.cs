using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace SweetsMachineCSharpClient
{
    [ComVisible(true)]
    [ComImport, Guid("69A4F43B-9D5E-4A2C-B66A-EBDAF5D365BA")]
    public class SweetsMachine
    {
    }

    // {005F63E5-810B-4247-B5BA-BD4810E7C09A}
    //DEFINE_GUID(IID_ICreateMachine,
    //	0x5f63e5, 0x810b, 0x4247, 0xb5, 0xba, 0xbd, 0x48, 0x10, 0xe7, 0xc0, 0x9a);
    [ComImport, InterfaceType(ComInterfaceType.InterfaceIsIUnknown), Guid("005F63E5-810B-4247-B5BA-BD4810E7C09A")]
    public interface ICreateMachine
    {
        void SetSerialNumber(string serialNumber);
        void SetMaxValue(int maxValue);
    }

    // {F5808472-3C3C-43A1-B44B-22349803B4EF}
    //DEFINE_GUID(IID_IStats,
    //	0xf5808472, 0x3c3c, 0x43a1, 0xb4, 0x4b, 0x22, 0x34, 0x98, 0x3, 0xb4, 0xef);
    [ComImport, InterfaceType(ComInterfaceType.InterfaceIsIUnknown), Guid("F5808472-3C3C-43A1-B44B-22349803B4EF")]
    public interface IStats
    {
        void DisplayStats();
        void GetSerialNumber(ref string serialNumber);
    }

    // {07AB4E07-C08E-485C-AC0C-FB0C55380296}
    //DEFINE_GUID(IID_ICoinAcceptor,
    //	0x7ab4e07, 0xc08e, 0x485c, 0xac, 0xc, 0xfb, 0xc, 0x55, 0x38, 0x2, 0x96);
    [ComImport, InterfaceType(ComInterfaceType.InterfaceIsIUnknown), Guid("07AB4E07-C08E-485C-AC0C-FB0C55380296")]
    public interface ICoinAcceptor
    {
        void BuyCandy();
        void GetMaxValue(ref int maxValue);
        void GetCurValue(ref int curValue);
    }
    static class Program
    {
        /// <summary>
        /// Главная точка входа для приложения.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }
    }
}
