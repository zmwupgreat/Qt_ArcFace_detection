void MainWidget::oninsertClicked()
{
    QString Path ="E:/arcface/ArcCropFace/Release/pic";
        int num = 299;
        QDir dir(Path);

        if(!dir.exists())
        {
            qDebug()<<"目录不存在";
            return;
        }
        dir.setFilter(QDir::Dirs);
        QFileInfoList dirlist = dir.entryInfoList();
        for(int i = 0; i < dirlist.count(); i++)
        {
            QDir photo_dir(dirlist.at(i).absoluteFilePath());
            if(dirlist.at(i).absoluteFilePath() == "E:/arcface/ArcCropFace/Release/pic" || dirlist.at(i).absoluteFilePath() == "E:/arcface/ArcCropFace/Release")
                continue;
            QStringList fileters;
            fileters<<QString("*.jpeg")<<QString("*.jpg")<<QString("*.png")<<QString("*.tiff")<<QString("*.gif")<<QString("*.bmp");
            photo_dir.setFilter(QDir::Files);
            photo_dir.setNameFilters(fileters);
            QFileInfoList photo_list = photo_dir.entryInfoList();
            QString filename = photo_list.at(0).absoluteFilePath();
            qDebug()<<filename;
            QFile::copy(filename,"./temp.bmp");
             Basic_Info basic_info;
             basic_info.Age ="10";
             basic_info.Apart = "技术部";
             basic_info.Gender = "男";
             QString str = QString::number(num);
             QString strNew = QString("%1").arg(str.toInt(), 6, 10, QLatin1Char('0'));
             basic_info.ID = strNew;
             basic_info.Name = strNew;
             AiFaceControl->setBasicInfo(basic_info);
             int Feature_size;
             QString imgpath = "./temp.bmp";
             bool msg = AiFaceControl->InsertFeature(strNew,imgpath,Feature_size);
             if(!msg)
                 continue;
             InFoStruct Info ;
             Info.Num = strNew;
             Info.Name = strNew;
             Info.Age = "10";
             Info.Apart = "技术部";
             Info.Gender = "男";
             Info.Feature = "./data/Feature/" + strNew + ".dat";
             Info.Feature_size = Feature_size;
             Info.Image = "./data/Image/" + strNew + ".bmp";
             bool Ret = infodb->InsertInfo(Info);
             if(!Ret)
                 continue;
             num++;
             qDebug()<<strNew;
             QFile::remove("./temp.bmp");
        }
}