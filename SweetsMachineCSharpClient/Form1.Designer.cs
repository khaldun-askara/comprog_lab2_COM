namespace SweetsMachineCSharpClient
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.panel1 = new System.Windows.Forms.Panel();
            this.button1 = new System.Windows.Forms.Button();
            this.label_maxval = new System.Windows.Forms.Label();
            this.label_curval = new System.Windows.Forms.Label();
            this.label_sernum = new System.Windows.Forms.Label();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.panel1.Controls.Add(this.button1);
            this.panel1.Controls.Add(this.label_maxval);
            this.panel1.Controls.Add(this.label_curval);
            this.panel1.Controls.Add(this.label_sernum);
            this.panel1.Location = new System.Drawing.Point(269, 14);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(296, 526);
            this.panel1.TabIndex = 1;
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.Color.Pink;
            this.button1.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.button1.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.button1.Font = new System.Drawing.Font("Impact", 25.8F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.button1.ForeColor = System.Drawing.SystemColors.Window;
            this.button1.Location = new System.Drawing.Point(0, 90);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(296, 436);
            this.button1.TabIndex = 4;
            this.button1.Text = "ХОЧЮ КОНФЕТУ";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // label_maxval
            // 
            this.label_maxval.AutoSize = true;
            this.label_maxval.Location = new System.Drawing.Point(15, 51);
            this.label_maxval.Name = "label_maxval";
            this.label_maxval.Size = new System.Drawing.Size(46, 17);
            this.label_maxval.TabIndex = 3;
            this.label_maxval.Text = "label1";
            // 
            // label_curval
            // 
            this.label_curval.AutoSize = true;
            this.label_curval.Location = new System.Drawing.Point(15, 34);
            this.label_curval.Name = "label_curval";
            this.label_curval.Size = new System.Drawing.Size(46, 17);
            this.label_curval.TabIndex = 2;
            this.label_curval.Text = "label1";
            // 
            // label_sernum
            // 
            this.label_sernum.AutoSize = true;
            this.label_sernum.Location = new System.Drawing.Point(15, 17);
            this.label_sernum.Name = "label_sernum";
            this.label_sernum.Size = new System.Drawing.Size(46, 17);
            this.label_sernum.TabIndex = 1;
            this.label_sernum.Text = "label1";
            // 
            // pictureBox1
            // 
            this.pictureBox1.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.pictureBox1.Image = global::SweetsMachineCSharpClient.Properties.Resources.SM;
            this.pictureBox1.Location = new System.Drawing.Point(12, 12);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(242, 529);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Window;
            this.ClientSize = new System.Drawing.Size(582, 553);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.pictureBox1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Form1";
            this.Text = "Sweets!!!";
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label_maxval;
        private System.Windows.Forms.Label label_curval;
        private System.Windows.Forms.Label label_sernum;
    }
}

